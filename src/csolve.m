% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize(quad_form(u_0, R) + quad_form(x_1 - x_ref_1, Q) + quad_form(u_1, R) + quad_form(x_2 - x_ref_2, Q) + quad_form(u_2, R) + quad_form(x_3 - x_ref_3, Q) + quad_form(u_3, R) + quad_form(x_4 - x_ref_4, Q) + quad_form(u_4, R) + quad_form(x_5 - x_ref_5, Q_final) + quad_form(u_1 - u_0, R_diff) + quad_form(u_2 - u_1, R_diff) + quad_form(u_3 - u_2, R_diff) + quad_form(u_4 - u_3, R_diff))
%   subject to
%     x_1 == A*x_0 + B*u_0 + C
%     x_2 == A*x_1 + B*u_1 + C
%     x_3 == A*x_2 + B*u_2 + C
%     x_4 == A*x_3 + B*u_3 + C
%     x_5 == A*x_4 + B*u_4 + C
%     x_min <= x_1
%     x_min <= x_2
%     x_min <= x_3
%     x_min <= x_4
%     x_min <= x_5
%     x_1 <= x_max
%     x_2 <= x_max
%     x_3 <= x_max
%     x_4 <= x_max
%     x_5 <= x_max
%     u_min <= u_0
%     u_min <= u_1
%     u_min <= u_2
%     u_min <= u_3
%     u_min <= u_4
%     u_0 <= u_max
%     u_1 <= u_max
%     u_2 <= u_max
%     u_3 <= u_max
%     u_4 <= u_max
%     abs(u_1(1) - u_0(1)) <= S
%     abs(u_2(1) - u_1(1)) <= S
%     abs(u_3(1) - u_2(1)) <= S
%     abs(u_4(1) - u_3(1)) <= S
%
% with variables
%      u_0   2 x 1
%      u_1   2 x 1
%      u_2   2 x 1
%      u_3   2 x 1
%      u_4   2 x 1
%      x_1   4 x 1
%      x_2   4 x 1
%      x_3   4 x 1
%      x_4   4 x 1
%      x_5   4 x 1
%
% and parameters
%        A   4 x 4
%        B   4 x 2
%        C   4 x 1
%        Q   4 x 4    PSD
%  Q_final   4 x 4    PSD
%        R   2 x 2    PSD
%   R_diff   2 x 2    PSD
%        S   1 x 1    positive
%    u_max   1 x 1    positive
%    u_min   1 x 1    negative
%      x_0   4 x 1
%    x_max   1 x 1    positive
%    x_min   1 x 1    negative
%  x_ref_1   4 x 1
%  x_ref_2   4 x 1
%  x_ref_3   4 x 1
%  x_ref_4   4 x 1
%  x_ref_5   4 x 1
%
% Note:
%   - Check status.converged, which will be 1 if optimization succeeded.
%   - You don't have to specify settings if you don't want to.
%   - To hide output, use settings.verbose = 0.
%   - To change iterations, use settings.max_iters = 20.
%   - You may wish to compare with cvxsolve to check the solver is correct.
%
% Specify params.A, ..., params.x_ref_5, then run
%   [vars, status] = csolve(params, settings)
% Produced by CVXGEN, 2020-03-22 19:57:34 -0400.
% CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2017 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
