from mpc_cvxgen.mpc import ModelPredictiveController
from mpc_cvxgen.utils import CubicSpline2D, global_config
import numpy as np

if __name__ == '__main__':
    test_wypts = np.asarray([
        [0, 10, 20, 10],
        [0, 60, 70, 100]
    ])
    spline = CubicSpline2D(test_wypts[0, :], test_wypts[1, :])
    ref_ss = np.arange(0, spline.s[-1], 1)
    ref_xs = [spline.calc_x(s) for s in ref_ss]
    ref_ys = [spline.calc_y(s) for s in ref_ss]
    ref_ks = [spline.calc_curvature(s) for s in ref_ss]
    ref_vels = [10 for s in ref_ss]
    ref_yaws = [spline.calc_yaw(s) for s in ref_ss]
    mpc_config = global_config
    mpc_config['reference'] = {
        't_list': [],
        's_list': ref_ss,  # Arc distance [m]
        'x_list': ref_xs,  # Desired X coordinates [m]
        'y_list': ref_ys,  # Desired Y coordinates [m]
        'k_list': ref_ks,  # Curvatures [1/m]
        'vel_list': ref_vels,  # Desired tangential velocities [m/s]
        'yaw_list': ref_yaws,  # Yaws [rad]
    }
    mpc = ModelPredictiveController(mpc_config)
    mpc.step()
    mpc_solution = [
        mpc.solution.t_list[1],
        mpc.solution.x_list[1],
        mpc.solution.y_list[1],
        mpc.solution.k_list[1],
        mpc.solution.vel_list[1],
        mpc.solution.yaw_list[1],
        mpc.solution.accel_list[0],
        mpc.solution.steer_list[0],
    ]
    print(mpc_solution)
