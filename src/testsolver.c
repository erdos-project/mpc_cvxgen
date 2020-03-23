/* Produced by CVXGEN, 2020-03-23 02:37:38 -0400.  */
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
  params.x_ref_1[0] = 0.20319161029830202;
  params.x_ref_1[1] = 0.8325912904724193;
  params.x_ref_1[2] = -0.8363810443482227;
  params.x_ref_1[3] = 0.04331042079065206;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.Q[0] = 1.8929469543476547;
  params.Q[4] = 0;
  params.Q[8] = 0;
  params.Q[12] = 0;
  params.Q[1] = 0;
  params.Q[5] = 1.896293088933438;
  params.Q[9] = 0;
  params.Q[13] = 0;
  params.Q[2] = 0;
  params.Q[6] = 0;
  params.Q[10] = 1.1255853104638363;
  params.Q[14] = 0;
  params.Q[3] = 0;
  params.Q[7] = 0;
  params.Q[11] = 0;
  params.Q[15] = 1.2072428781381868;
  params.x_ref_2[0] = -1.7941311867966805;
  params.x_ref_2[1] = -0.23676062539745413;
  params.x_ref_2[2] = -1.8804951564857322;
  params.x_ref_2[3] = -0.17266710242115568;
  params.x_ref_3[0] = 0.596576190459043;
  params.x_ref_3[1] = -0.8860508694080989;
  params.x_ref_3[2] = 0.7050196079205251;
  params.x_ref_3[3] = 0.3634512696654033;
  params.x_ref_4[0] = -1.9040724704913385;
  params.x_ref_4[1] = 0.23541635196352795;
  params.x_ref_4[2] = -0.9629902123701384;
  params.x_ref_4[3] = -0.3395952119597214;
  params.x_ref_5[0] = -0.865899672914725;
  params.x_ref_5[1] = 0.7725516732519853;
  params.x_ref_5[2] = -0.23818512931704205;
  params.x_ref_5[3] = -1.372529046100147;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.Q_final[0] = 1.5446490180318446;
  params.Q_final[4] = 0;
  params.Q_final[8] = 0;
  params.Q_final[12] = 0;
  params.Q_final[1] = 0;
  params.Q_final[5] = 1.780314764511367;
  params.Q_final[9] = 0;
  params.Q_final[13] = 0;
  params.Q_final[2] = 0;
  params.Q_final[6] = 0;
  params.Q_final[10] = 1.3063635323761797;
  params.Q_final[14] = 0;
  params.Q_final[3] = 0;
  params.Q_final[7] = 0;
  params.Q_final[11] = 0;
  params.Q_final[15] = 1.2219578839321814;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.R[0] = 1.3879712575556487;
  params.R[2] = 0;
  params.R[1] = 0;
  params.R[3] = 1.9363836498604305;
  /* Make this a diagonal PSD matrix, even though it's not diagonal. */
  params.R_diff[0] = 1.9759954224729337;
  params.R_diff[2] = 0;
  params.R_diff[1] = 0;
  params.R_diff[3] = 1.6723836759128137;
  params.A_0[0] = 1.6113364341535923;
  params.A_0[1] = 1.383003485172717;
  params.A_0[2] = -0.48802383468444344;
  params.A_0[3] = -1.631131964513103;
  params.A_0[4] = 0.6136436100941447;
  params.A_0[5] = 0.2313630495538037;
  params.A_0[6] = -0.5537409477496875;
  params.A_0[7] = -1.0997819806406723;
  params.A_0[8] = -0.3739203344950055;
  params.A_0[9] = -0.12423900520332376;
  params.A_0[10] = -0.923057686995755;
  params.A_0[11] = -0.8328289030982696;
  params.A_0[12] = -0.16925440270808823;
  params.A_0[13] = 1.442135651787706;
  params.A_0[14] = 0.34501161787128565;
  params.A_0[15] = -0.8660485502711608;
  params.x_0[0] = -0.8880899735055947;
  params.x_0[1] = -0.1815116979122129;
  params.x_0[2] = -1.17835862158005;
  params.x_0[3] = -1.1944851558277074;
  params.B_0[0] = 0.05614023926976763;
  params.B_0[1] = -1.6510825248767813;
  params.B_0[2] = -0.06565787059365391;
  params.B_0[3] = -0.5512951504486665;
  params.B_0[4] = 0.8307464872626844;
  params.B_0[5] = 0.9869848924080182;
  params.B_0[6] = 0.7643716874230573;
  params.B_0[7] = 0.7567216550196565;
  params.C_0[0] = -0.5055995034042868;
  params.C_0[1] = 0.6725392189410702;
  params.C_0[2] = -0.6406053441727284;
  params.C_0[3] = 0.29117547947550015;
  params.A_1[0] = -0.6967713677405021;
  params.A_1[1] = -0.21941980294587182;
  params.A_1[2] = -1.753884276680243;
  params.A_1[3] = -1.0292983112626475;
  params.A_1[4] = 1.8864104246942706;
  params.A_1[5] = -1.077663182579704;
  params.A_1[6] = 0.7659100437893209;
  params.A_1[7] = 0.6019074328549583;
  params.A_1[8] = 0.8957565577499285;
  params.A_1[9] = -0.09964555746227477;
  params.A_1[10] = 0.38665509840745127;
  params.A_1[11] = -1.7321223042686946;
  params.A_1[12] = -1.7097514487110663;
  params.A_1[13] = -1.2040958948116867;
  params.A_1[14] = -1.3925560119658358;
  params.A_1[15] = -1.5995826216742213;
  params.B_1[0] = -1.4828245415645833;
  params.B_1[1] = 0.21311092723061398;
  params.B_1[2] = -1.248740700304487;
  params.B_1[3] = 1.808404972124833;
  params.B_1[4] = 0.7264471152297065;
  params.B_1[5] = 0.16407869343908477;
  params.B_1[6] = 0.8287224032315907;
  params.B_1[7] = -0.9444533161899464;
  params.C_1[0] = 1.7069027370149112;
  params.C_1[1] = 1.3567722311998827;
  params.C_1[2] = 0.9052779937121489;
  params.C_1[3] = -0.07904017565835986;
  params.A_2[0] = 1.3684127435065871;
  params.A_2[1] = 0.979009293697437;
  params.A_2[2] = 0.6413036255984501;
  params.A_2[3] = 1.6559010680237511;
  params.A_2[4] = 0.5346622551502991;
  params.A_2[5] = -0.5362376605895625;
  params.A_2[6] = 0.2113782926017822;
  params.A_2[7] = -1.2144776931994525;
  params.A_2[8] = -1.2317108144255875;
  params.A_2[9] = 0.9026784957312834;
  params.A_2[10] = 1.1397468137245244;
  params.A_2[11] = 1.8883934547350631;
  params.A_2[12] = 1.4038856681660068;
  params.A_2[13] = 0.17437730638329096;
  params.A_2[14] = -1.6408365219077408;
  params.A_2[15] = -0.04450702153554875;
  params.B_2[0] = 1.7117453902485025;
  params.B_2[1] = 1.1504727980139053;
  params.B_2[2] = -0.05962309578364744;
  params.B_2[3] = -0.1788825540764547;
  params.B_2[4] = -1.1280569263625857;
  params.B_2[5] = -1.2911464767927057;
  params.B_2[6] = -1.7055053231225696;
  params.B_2[7] = 1.56957275034837;
  params.C_2[0] = 0.5607064675962357;
  params.C_2[1] = -1.4266707301147146;
  params.C_2[2] = -0.3434923211351708;
  params.C_2[3] = -1.8035643024085055;
  params.A_3[0] = -1.1625066019105454;
  params.A_3[1] = 0.9228324965161532;
  params.A_3[2] = 0.6044910817663975;
  params.A_3[3] = -0.0840868104920891;
  params.A_3[4] = -0.900877978017443;
  params.A_3[5] = 0.608892500264739;
  params.A_3[6] = 1.8257980452695217;
  params.A_3[7] = -0.25791777529922877;
  params.A_3[8] = -1.7194699796493191;
  params.A_3[9] = -1.7690740487081298;
  params.A_3[10] = -1.6685159248097703;
  params.A_3[11] = 1.8388287490128845;
  params.A_3[12] = 0.16304334474597537;
  params.A_3[13] = 1.3498497306788897;
  params.A_3[14] = -1.3198658230514613;
  params.A_3[15] = -0.9586197090843394;
  params.B_3[0] = 0.7679100474913709;
  params.B_3[1] = 1.5822813125679343;
  params.B_3[2] = -0.6372460621593619;
  params.B_3[3] = -1.741307208038867;
  params.B_3[4] = 1.456478677642575;
  params.B_3[5] = -0.8365102166820959;
  params.B_3[6] = 0.9643296255982503;
  params.B_3[7] = -1.367865381194024;
  params.C_3[0] = 0.7798537405635035;
  params.C_3[1] = 1.3656784761245926;
  params.C_3[2] = 0.9086083149868371;
  params.C_3[3] = -0.5635699005460344;
  params.A_4[0] = 0.9067590059607915;
  params.A_4[1] = -1.4421315032701587;
  params.A_4[2] = -0.7447235390671119;
  params.A_4[3] = -0.32166897326822186;
  params.A_4[4] = 1.5088481557772684;
  params.A_4[5] = -1.385039165715428;
  params.A_4[6] = 1.5204991609972622;
  params.A_4[7] = 1.1958572768832156;
  params.A_4[8] = 1.8864971883119228;
  params.A_4[9] = -0.5291880667861584;
  params.A_4[10] = -1.1802409243688836;
  params.A_4[11] = -1.037718718661604;
  params.A_4[12] = 1.3114512056856835;
  params.A_4[13] = 1.8609125943756615;
  params.A_4[14] = 0.7952399935216938;
  params.A_4[15] = -0.07001183290468038;
  params.B_4[0] = -0.8518009412754686;
  params.B_4[1] = 1.3347515373726386;
  params.B_4[2] = 1.4887180335977037;
  params.B_4[3] = -1.6314736327976336;
  params.B_4[4] = -1.1362021159208933;
  params.B_4[5] = 1.327044361831466;
  params.B_4[6] = 1.3932155883179842;
  params.B_4[7] = -0.7413880049440107;
  params.C_4[0] = -0.8828216126125747;
  params.C_4[1] = -0.27673991192616;
  params.C_4[2] = 0.15778600105866714;
  params.C_4[3] = -1.6177327399735457;
  params.vel_min[0] = 1.6738242774272303;
  params.vel_max[0] = 1.069469740702642;
  params.accel_min[0] = -1.5499356300818472;
  params.accel_max[0] = 0.4616725311526537;
  params.steer_min[0] = -1.9305867022127314;
  params.steer_max[0] = 1.5020546146367586;
  params.steer_rate_lim[0] = 0.6861877287839229;
}
