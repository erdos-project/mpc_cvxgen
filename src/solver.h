/* Produced by CVXGEN, 2020-02-24 13:45:14 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: solver.h. */
/* Description: Header file with relevant definitions. */
#ifndef SOLVER_H
#define SOLVER_H
/* Uncomment the next line to remove all library dependencies. */
/*#define ZERO_LIBRARY_MODE */
#ifdef MATLAB_MEX_FILE
/* Matlab functions. MATLAB_MEX_FILE will be defined by the mex compiler. */
/* If you are not using the mex compiler, this functionality will not intrude, */
/* as it will be completely disabled at compile-time. */
#include "mex.h"
#else
#ifndef ZERO_LIBRARY_MODE
#include <stdio.h>
#endif
#endif
/* Space must be allocated somewhere (testsolver.c, csolve.c or your own */
/* program) for the global variables vars, params, work and settings. */
/* At the bottom of this file, they are externed. */
#ifndef ZERO_LIBRARY_MODE
#include <math.h>
#define pm(A, m, n) printmatrix(#A, A, m, n, 1)
#endif
typedef struct Params_t {
  double R[4];
  double x_ref_1[4];
  double Q[16];
  double x_ref_2[4];
  double x_ref_3[4];
  double x_ref_4[4];
  double x_ref_5[4];
  double x_ref_6[4];
  double x_ref_7[4];
  double x_ref_8[4];
  double x_ref_9[4];
  double x_ref_10[4];
  double x_ref_11[4];
  double Q_final[16];
  double A[16];
  double x_0[4];
  double B[8];
  double x_max[1];
  double u_max[1];
  double S[1];
  double *x_ref[12];
  double *x[1];
} Params;
typedef struct Vars_t {
  double *u_0; /* 2 rows. */
  double *x_1; /* 4 rows. */
  double *u_1; /* 2 rows. */
  double *x_2; /* 4 rows. */
  double *u_2; /* 2 rows. */
  double *x_3; /* 4 rows. */
  double *u_3; /* 2 rows. */
  double *x_4; /* 4 rows. */
  double *u_4; /* 2 rows. */
  double *x_5; /* 4 rows. */
  double *u_5; /* 2 rows. */
  double *x_6; /* 4 rows. */
  double *u_6; /* 2 rows. */
  double *x_7; /* 4 rows. */
  double *u_7; /* 2 rows. */
  double *x_8; /* 4 rows. */
  double *u_8; /* 2 rows. */
  double *x_9; /* 4 rows. */
  double *u_9; /* 2 rows. */
  double *x_10; /* 4 rows. */
  double *u_10; /* 2 rows. */
  double *x_11; /* 4 rows. */
  double *t_01; /* 4 rows. */
  double *t_02; /* 4 rows. */
  double *t_03; /* 4 rows. */
  double *t_04; /* 4 rows. */
  double *t_05; /* 4 rows. */
  double *t_06; /* 4 rows. */
  double *t_07; /* 4 rows. */
  double *t_08; /* 4 rows. */
  double *t_09; /* 4 rows. */
  double *t_10; /* 4 rows. */
  double *t_11; /* 4 rows. */
  double *t_12; /* 2 rows. */
  double *t_13; /* 2 rows. */
  double *t_14; /* 2 rows. */
  double *t_15; /* 2 rows. */
  double *t_16; /* 2 rows. */
  double *t_17; /* 2 rows. */
  double *t_18; /* 2 rows. */
  double *t_19; /* 2 rows. */
  double *t_20; /* 2 rows. */
  double *t_21; /* 2 rows. */
  double *t_22; /* 2 rows. */
  double *t_23; /* 1 rows. */
  double *t_24; /* 1 rows. */
  double *t_25; /* 1 rows. */
  double *t_26; /* 1 rows. */
  double *t_27; /* 1 rows. */
  double *t_28; /* 1 rows. */
  double *t_29; /* 1 rows. */
  double *t_30; /* 1 rows. */
  double *t_31; /* 1 rows. */
  double *t_32; /* 1 rows. */
  double *u[11];
  double *x[12];
} Vars;
typedef struct Workspace_t {
  double h[248];
  double s_inv[248];
  double s_inv_z[248];
  double b[44];
  double q[142];
  double rhs[682];
  double x[682];
  double *s;
  double *z;
  double *y;
  double lhs_aff[682];
  double lhs_cc[682];
  double buffer[682];
  double buffer2[682];
  double KKT[1639];
  double L[1530];
  double d[682];
  double v[682];
  double d_inv[682];
  double gap;
  double optval;
  double ineq_resid_squared;
  double eq_resid_squared;
  double block_33[1];
  /* Pre-op symbols. */
  double quad_17600004096[1];
  double quad_825882382336[1];
  double quad_43289251840[1];
  double quad_936874864640[1];
  double quad_749185671168[1];
  double quad_751015542784[1];
  double quad_28412862464[1];
  double quad_599520112640[1];
  double quad_612073590784[1];
  double quad_324497137664[1];
  double quad_762992287744[1];
  int converged;
} Workspace;
typedef struct Settings_t {
  double resid_tol;
  double eps;
  int max_iters;
  int refine_steps;
  int better_start;
  /* Better start obviates the need for s_init and z_init. */
  double s_init;
  double z_init;
  int verbose;
  /* Show extra details of the iterative refinement steps. */
  int verbose_refinement;
  int debug;
  /* For regularization. Minimum value of abs(D_ii) in the kkt D factor. */
  double kkt_reg;
} Settings;
extern Vars vars;
extern Params params;
extern Workspace work;
extern Settings settings;
/* Function definitions in ldl.c: */
void ldl_solve(double *target, double *var);
void ldl_factor(void);
double check_factorization(void);
void matrix_multiply(double *result, double *source);
double check_residual(double *target, double *multiplicand);
void fill_KKT(void);

/* Function definitions in matrix_support.c: */
void multbymA(double *lhs, double *rhs);
void multbymAT(double *lhs, double *rhs);
void multbymG(double *lhs, double *rhs);
void multbymGT(double *lhs, double *rhs);
void multbyP(double *lhs, double *rhs);
void fillq(void);
void fillh(void);
void fillb(void);
void pre_ops(void);

/* Function definitions in solver.c: */
double eval_gap(void);
void set_defaults(void);
void setup_pointers(void);
void setup_indexed_params(void);
void setup_indexed_optvars(void);
void setup_indexing(void);
void set_start(void);
double eval_objv(void);
void fillrhs_aff(void);
void fillrhs_cc(void);
void refine(double *target, double *var);
double calc_ineq_resid_squared(void);
double calc_eq_resid_squared(void);
void better_start(void);
void fillrhs_start(void);
long solve(void);

/* Function definitions in testsolver.c: */
int main(int argc, char **argv);
void load_default_data(void);

/* Function definitions in util.c: */
void tic(void);
float toc(void);
float tocq(void);
void printmatrix(char *name, double *A, int m, int n, int sparse);
double unif(double lower, double upper);
float ran1(long*idum, int reset);
float randn_internal(long *idum, int reset);
double randn(void);
void reset_rand(void);

#endif
