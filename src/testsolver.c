/* Produced by CVXGEN, 2020-02-24 13:45:14 -0500.  */
/* CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com. */
/* The code in this file is Copyright (C) 2006-2017 Jacob Mattingley. */
/* CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial */
/* applications without prior written permission from Jacob Mattingley. */

/* Filename: testsolver.c. */
/* Description: Basic test harness for solver.c. */
#include "solver.h"
Vars vars;
Params params;
Workspace work;
Settings settings;
#define NUMTESTS 0
int main(int argc, char **argv) {
  int num_iters;
#if (NUMTESTS > 0)
  int i;
  double time;
  double time_per;
#endif
  set_defaults();
  setup_indexing();
  load_default_data();
  /* Solve problem instance for the record. */
  settings.verbose = 1;
  num_iters = solve();
#ifndef ZERO_LIBRARY_MODE
#if (NUMTESTS > 0)
  /* Now solve multiple problem instances for timing purposes. */
  settings.verbose = 0;
  tic();
  for (i = 0; i < NUMTESTS; i++) {
    solve();
  }
  time = tocq();
  printf("Timed %d solves over %.3f seconds.\n", NUMTESTS, time);
  time_per = time / NUMTESTS;
  if (time_per > 1) {
    printf("Actual time taken per solve: %.3g s.\n", time_per);
  } else if (time_per > 1e-3) {
    printf("Actual time taken per solve: %.3g ms.\n", 1e3*time_per);
  } else {
    printf("Actual time taken per solve: %.3g us.\n", 1e6*time_per);
  }
#endif
#endif
  return 0;
}
void load_default_data(void) {
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.R[0] = 1.5507979025745755;
  params.R[2] = 0;
  params.R[1] = 0;
  params.R[3] = 1.7081478226181048;
  params.x_ref_1[0] = -0.8363810443482227;
  params.x_ref_1[1] = 0.04331042079065206;
  params.x_ref_1[2] = 1.5717878173906188;
  params.x_ref_1[3] = 1.5851723557337523;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.Q[0] = 1.1255853104638363;
  params.Q[4] = 0;
  params.Q[8] = 0;
  params.Q[12] = 0;
  params.Q[1] = 0;
  params.Q[5] = 1.2072428781381868;
  params.Q[9] = 0;
  params.Q[13] = 0;
  params.Q[2] = 0;
  params.Q[6] = 0;
  params.Q[10] = 1.0514672033008299;
  params.Q[14] = 0;
  params.Q[3] = 0;
  params.Q[7] = 0;
  params.Q[11] = 0;
  params.Q[15] = 1.4408098436506365;
  params.x_ref_2[0] = -1.8804951564857322;
  params.x_ref_2[1] = -0.17266710242115568;
  params.x_ref_2[2] = 0.596576190459043;
  params.x_ref_2[3] = -0.8860508694080989;
  params.x_ref_3[0] = 0.7050196079205251;
  params.x_ref_3[1] = 0.3634512696654033;
  params.x_ref_3[2] = -1.9040724704913385;
  params.x_ref_3[3] = 0.23541635196352795;
  params.x_ref_4[0] = -0.9629902123701384;
  params.x_ref_4[1] = -0.3395952119597214;
  params.x_ref_4[2] = -0.865899672914725;
  params.x_ref_4[3] = 0.7725516732519853;
  params.x_ref_5[0] = -0.23818512931704205;
  params.x_ref_5[1] = -1.372529046100147;
  params.x_ref_5[2] = 0.17859607212737894;
  params.x_ref_5[3] = 1.1212590580454682;
  params.x_ref_6[0] = -0.774545870495281;
  params.x_ref_6[1] = -1.1121684642712744;
  params.x_ref_6[2] = -0.44811496977740495;
  params.x_ref_6[3] = 1.7455345994417217;
  params.x_ref_7[0] = 1.9039816898917352;
  params.x_ref_7[1] = 0.6895347036512547;
  params.x_ref_7[2] = 1.6113364341535923;
  params.x_ref_7[3] = 1.383003485172717;
  params.x_ref_8[0] = -0.48802383468444344;
  params.x_ref_8[1] = -1.631131964513103;
  params.x_ref_8[2] = 0.6136436100941447;
  params.x_ref_8[3] = 0.2313630495538037;
  params.x_ref_9[0] = -0.5537409477496875;
  params.x_ref_9[1] = -1.0997819806406723;
  params.x_ref_9[2] = -0.3739203344950055;
  params.x_ref_9[3] = -0.12423900520332376;
  params.x_ref_10[0] = -0.923057686995755;
  params.x_ref_10[1] = -0.8328289030982696;
  params.x_ref_10[2] = -0.16925440270808823;
  params.x_ref_10[3] = 1.442135651787706;
  params.x_ref_11[0] = 0.34501161787128565;
  params.x_ref_11[1] = -0.8660485502711608;
  params.x_ref_11[2] = -0.8880899735055947;
  params.x_ref_11[3] = -0.1815116979122129;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.Q_final[0] = 1.2054103446049875;
  params.Q_final[4] = 0;
  params.Q_final[8] = 0;
  params.Q_final[12] = 0;
  params.Q_final[1] = 0;
  params.Q_final[5] = 1.2013787110430731;
  params.Q_final[9] = 0;
  params.Q_final[13] = 0;
  params.Q_final[2] = 0;
  params.Q_final[6] = 0;
  params.Q_final[10] = 1.514035059817442;
  params.Q_final[14] = 0;
  params.Q_final[3] = 0;
  params.Q_final[7] = 0;
  params.Q_final[11] = 0;
  params.Q_final[15] = 1.0872293687808048;
  params.A[0] = -0.06565787059365391;
  params.A[1] = -0.5512951504486665;
  params.A[2] = 0.8307464872626844;
  params.A[3] = 0.9869848924080182;
  params.A[4] = 0.7643716874230573;
  params.A[5] = 0.7567216550196565;
  params.A[6] = -0.5055995034042868;
  params.A[7] = 0.6725392189410702;
  params.A[8] = -0.6406053441727284;
  params.A[9] = 0.29117547947550015;
  params.A[10] = -0.6967713677405021;
  params.A[11] = -0.21941980294587182;
  params.A[12] = -1.753884276680243;
  params.A[13] = -1.0292983112626475;
  params.A[14] = 1.8864104246942706;
  params.A[15] = -1.077663182579704;
  params.x_0[0] = 0.7659100437893209;
  params.x_0[1] = 0.6019074328549583;
  params.x_0[2] = 0.8957565577499285;
  params.x_0[3] = -0.09964555746227477;
  params.B[0] = 0.38665509840745127;
  params.B[1] = -1.7321223042686946;
  params.B[2] = -1.7097514487110663;
  params.B[3] = -1.2040958948116867;
  params.B[4] = -1.3925560119658358;
  params.B[5] = -1.5995826216742213;
  params.B[6] = -1.4828245415645833;
  params.B[7] = 0.21311092723061398;
  params.x_max[0] = 0.3756296498477565;
  params.u_max[0] = 1.9042024860624165;
  params.S[0] = 1.3632235576148533;
}
