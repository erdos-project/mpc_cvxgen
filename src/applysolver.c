/* Produced by CVXGEN, 2020-03-22 05:22:57 -0400.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: applysolver.c. */
/* Description: Basic apply wrapper for solver.c. */
#include "solver.h"
Vars vars;
Params params;
Workspace work;
Settings settings;
int M = 2;  // Input dimension
int N = 4;  // State dimension
int T = 5;  // Time horizon
int apply_solver(double* x_0,
                 double* x_ref_1, double* x_ref_2, double* x_ref_3, double* x_ref_4, double* x_ref_5,
                 double* A_0, double* A_1, double* A_2, double* A_3, double* A_4,
                 double* B_0, double* B_1, double* B_2, double* B_3, double* B_4,
                 double* C_0, double* C_1, double* C_2, double* C_3, double* C_4,
                 double* Q, double* Q_final, double* R, double* R_diff,
                 double vel_max, double vel_min, double accel_max, double accel_min,
                 double steer_max, double steer_min, double steer_rate_lim,
                 double* x_sol, double* u_sol) {
  /* Pass parameters */
  // Set x_0 and x_ref vectors
  for (int i = 0; i < N; i++) {
    params.x_0[i] = x_0[i];
    params.x_ref_1[i] = x_ref_1[i];
    params.x_ref_2[i] = x_ref_2[i];
    params.x_ref_3[i] = x_ref_3[i];
    params.x_ref_4[i] = x_ref_4[i];
    params.x_ref_5[i] = x_ref_5[i];
  }
  // Set A, B, and C matrices
  for (int i = 0; i < N; i++) {
    params.C_0[i] = C_0[i];
    params.C_1[i] = C_1[i];
    params.C_2[i] = C_2[i];
    params.C_3[i] = C_3[i];
    params.C_4[i] = C_4[i];
    for (int j = 0; j < N; j++) {
      params.A_0[i+j*N] = A_0[i+j*N];
      params.A_1[i+j*N] = A_1[i+j*N];
      params.A_2[i+j*N] = A_2[i+j*N];
      params.A_3[i+j*N] = A_3[i+j*N];
      params.A_4[i+j*N] = A_4[i+j*N];
    }
    for (int j = 0; j < M; j++) {
      params.B_0[i+j*N] = B_0[i+j*N];
      params.B_1[i+j*N] = B_1[i+j*N];
      params.B_2[i+j*N] = B_2[i+j*N];
      params.B_3[i+j*N] = B_3[i+j*N];
      params.B_4[i+j*N] = B_4[i+j*N];
    }
  }
//  printf("B_0\n");
//  for (int i = 0; i < N; i++) {
//    for (int j = 0; j < M; j++) {
//      printf("  %9.4f\t", params.B_0[i+j*N]);
//    }
//    printf("\n");
//  }
  // Set Q, Q_final, R, and R_diff matrices
  for (int i = 0; i < N; i++) {
    params.R[i] = R[i];
    params.R_diff[i] = R_diff[i];
    for (int j = 0; j < N; j++) {
      params.Q[i+j*N] = Q[i+j*N];
      params.Q_final[i+j*N] = Q[i+j*N];
    }
  }
  // Set x_max, x_min, u_max, u_min, and S
  params.vel_max[0] = vel_max;
  params.vel_min[0] = vel_min;
  params.accel_max[0] = accel_max;
  params.accel_min[0] = accel_min;
  params.steer_max[0] = steer_max;
  params.steer_min[0] = steer_min;
  params.steer_rate_lim[0] = steer_rate_lim;

  int num_iters;
  set_defaults();
  setup_indexing();
  /* Solve problem instance for the record. */
  settings.verbose = 0;
  num_iters = solve();

  /* Return solution */
  for (int i = 0; i < N; i++) {
    x_sol[i+0*N] = vars.x_1[i];
    x_sol[i+1*N] = vars.x_2[i];
    x_sol[i+2*N] = vars.x_3[i];
    x_sol[i+3*N] = vars.x_4[i];
    x_sol[i+4*N] = vars.x_5[i];
  }
  for (int i = 0; i < M; i++) {
    u_sol[i+0*M] = vars.u_0[i];
    u_sol[i+1*M] = vars.u_1[i];
    u_sol[i+2*M] = vars.u_2[i];
    u_sol[i+3*M] = vars.u_3[i];
    u_sol[i+4*M] = vars.u_4[i];
  }
  return 0;
}
