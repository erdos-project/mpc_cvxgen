"""
Author: Fangyu Wu, Edward Fang
Email: fangyuwu@berkeley.edu, edward.fang@berkeley.edu

The code is adapted from https://github.com/AtsushiSakai/PythonRobotics/tree/
master/PathTracking/model_predictive_speed_and_steer_control.
Its author is Atsushi Sakai.

Reference Papers:
- [Kinematic and Dynamic Vehicle Models for Autonomous Driving Control Design]
(https://borrelli.me.berkeley.edu/pdfpub/IV_KinematicMPC_jason.pdf)
"""
import ctypes
from ctypes import c_double, c_int
from mpc_cvxgen.mpc import ModelPredictiveController
import numpy as np
import os

path = os.path.abspath(__file__).split('/')[:-3]
path = '{}/build/applysolver.so'.format('/'.join(path))
if os.path.exists(path):
    cdll = ctypes.CDLL(path)
else:
    raise ValueError('Shared library applysolver.so is not found.')
c_double_p = ctypes.POINTER(c_double)
cdll.apply_solver.argtypes = (
    c_double_p,
    c_double_p, c_double_p, c_double_p, c_double_p, c_double_p,
    c_double_p, c_double_p, c_double_p, c_double_p, c_double_p,
    c_double_p, c_double_p, c_double_p, c_double_p, c_double_p,
    c_double_p, c_double_p, c_double_p, c_double_p, c_double_p,
    c_double_p, c_double_p, c_double_p, c_double_p,
    c_double, c_double, c_double, c_double,
    c_double, c_double, c_double,
    c_double_p, c_double_p
)
cdll.apply_solver.restype = c_int


class ModelPredictiveControllerCVXGEN(ModelPredictiveController):
    def _control(self, reference_state, predicted_state, reference_steer):
        """
        Solve the MPC control problem using the cvxgen solver.

        :param reference_state: np.array of reference states
        :param predicted_state: np.array of predicted states obtained using
            propogated controls
        :param reference_steer: np.array of reference steering
        :return:
        """
        # initial state
        x_0 = np.copy(self.vehicle.get_state()).flatten('F').astype(np.float64)
        c_x_0 = x_0.ctypes.data_as(c_double_p)

        # iterate over the horizon
        c_x_ref = []
        c_mat_a = []
        c_mat_b = []
        c_mat_c = []
        for t in range(self.config['horizon']):
            x_ref = reference_state[:, t].flatten('F').astype(np.float64)
            c_x_ref.append(x_ref.ctypes.data_as(c_double_p))
            matrix_a, matrix_b, matrix_c = self._linearized_model_matrix(
                predicted_state[2, t], predicted_state[3, t],
                reference_steer[0, t])
            matrix_a = np.array(matrix_a).flatten(order='F').astype(np.float64)
            c_mat_a.append(matrix_a.ctypes.data_as(c_double_p))
            matrix_b = np.array(matrix_b).flatten(order='F').astype(np.float64)
            c_mat_b.append(matrix_b.ctypes.data_as(c_double_p))
            matrix_c = np.array(matrix_c).flatten(order='F').astype(np.float64)
            c_mat_c.append(matrix_c.ctypes.data_as(c_double_p))

        mat_q = self.config['Q'].flatten(order='F').astype(np.float64)
        c_mat_q = mat_q.ctypes.data_as(c_double_p)
        mat_qf = self.config['Qf'].flatten(order='F').astype(np.float64)
        c_mat_qf = mat_qf.ctypes.data_as(c_double_p)
        mat_r = self.config['R'].flatten(order='F').astype(np.float64)
        c_mat_r = mat_r.ctypes.data_as(c_double_p)
        mat_rd = self.config['Rd'].flatten(order='F').astype(np.float64)
        c_mat_rd = mat_rd.ctypes.data_as(c_double_p)

        c_vel_max = c_double(self.vehicle.config['max_vel'])
        c_vel_min = c_double(self.vehicle.config['min_vel'])
        c_accel_max = c_double(self.vehicle.config['max_accel'])
        c_accel_min = c_double(self.vehicle.config['min_accel'])
        c_steer_max = c_double(self.vehicle.config['max_steer'])
        c_steer_min = c_double(self.vehicle.config['min_steer'])
        c_steer_rate_lim = c_double(self.vehicle.config['max_steer_speed'])

        x_sol = np.zeros(self.config['horizon'] * self.num_state)
        c_x_sol = x_sol.ctypes.data_as(c_double_p)
        u_sol = np.zeros(self.config['horizon'] * self.num_input)
        c_u_sol = u_sol.ctypes.data_as(c_double_p)

        cdll.apply_solver(
            c_x_0,
            c_x_ref[0], c_x_ref[1], c_x_ref[2], c_x_ref[3], c_x_ref[4],
            c_mat_a[0], c_mat_a[1], c_mat_a[2], c_mat_a[3], c_mat_a[4],
            c_mat_b[0], c_mat_b[1], c_mat_b[2], c_mat_b[3], c_mat_b[4],
            c_mat_c[0], c_mat_c[1], c_mat_c[2], c_mat_c[3], c_mat_c[4],
            c_mat_q, c_mat_qf, c_mat_r, c_mat_rd,
            c_vel_max, c_vel_min, c_accel_max, c_accel_min,
            c_steer_max, c_steer_min, c_steer_rate_lim,
            c_x_sol, c_u_sol
        )

        # return solution
        x_sol = x_sol.reshape(
            (self.num_state, self.config['horizon']), order='F')
        u_sol = u_sol.reshape(
            (self.num_input, self.config['horizon']), order='F')
        horizon_x = np.array(x_sol[0, :]).flatten()
        horizon_y = np.array(x_sol[1, :]).flatten()
        horizon_vel = np.array(x_sol[2, :]).flatten()
        horizon_yaw = np.array(x_sol[3, :]).flatten()
        horizon_accel = np.array(u_sol[0, :]).flatten()
        horizon_steer = np.array(u_sol[1, :]).flatten()

        return horizon_x, horizon_y, horizon_vel, horizon_yaw, horizon_accel, \
            horizon_steer, True
