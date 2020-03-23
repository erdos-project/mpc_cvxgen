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
                 double* A, double* B, double* C,
                 double* Q, double* Q_final, double* R, double* R_diff,
                 double x_max, double x_min, double u_max, double u_min, double S,
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
    params.C[i] = C[i];
    for (int j = 0; j < N; j++) {
      params.A[i+j*N] = A[i+j*N];
      params.B[i+j*N] = B[i+j*N];
    }
  }
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
  params.x_max[0] = x_max;
  params.x_min[0] = x_min;
  params.u_max[0] = u_max;
  params.u_min[0] = u_min;
  params.S[0] = S;

  int num_iters;
  set_defaults();
  setup_indexing();
  /* Solve problem instance for the record. */
  settings.verbose = 1;
  num_iters = solve();

  /* Return solution */
  for (int t = 0; t < T; t++) {
    for (int i = 0; i < N; i++)
      x_sol[t+i*T] = vars.x[t][i];
    for (int i = 0; i < M; i++)
      u_sol[t+i*T] = vars.u[t][i];
  }
  return 0;
}
