% csolve  Solves a custom quadratic program very rapidly.
%
% [vars, status] = csolve(params, settings)
%
% solves the convex optimization problem
%
%   minimize(quad_form(u_0, R) + quad_form(x_1 - x_ref_1, Q) + quad_form(u_1, R) + quad_form(x_2 - x_ref_2, Q) + quad_form(u_2, R) + quad_form(x_3 - x_ref_3, Q) + quad_form(u_3, R) + quad_form(x_4 - x_ref_4, Q) + quad_form(u_4, R) + quad_form(x_5 - x_ref_5, Q) + quad_form(u_5, R) + quad_form(x_6 - x_ref_6, Q) + quad_form(u_6, R) + quad_form(x_7 - x_ref_7, Q) + quad_form(u_7, R) + quad_form(x_8 - x_ref_8, Q) + quad_form(u_8, R) + quad_form(x_9 - x_ref_9, Q) + quad_form(u_9, R) + quad_form(x_10 - x_ref_10, Q) + quad_form(u_10, R) + quad_form(x_11 - x_ref_11, Q_final))
%   subject to
%     x_1 == A*x_0 + B*u_0
%     x_2 == A*x_1 + B*u_1
%     x_3 == A*x_2 + B*u_2
%     x_4 == A*x_3 + B*u_3
%     x_5 == A*x_4 + B*u_4
%     x_6 == A*x_5 + B*u_5
%     x_7 == A*x_6 + B*u_6
%     x_8 == A*x_7 + B*u_7
%     x_9 == A*x_8 + B*u_8
%     x_10 == A*x_9 + B*u_9
%     x_11 == A*x_10 + B*u_10
%     abs(x_1) <= x_max
%     abs(x_2) <= x_max
%     abs(x_3) <= x_max
%     abs(x_4) <= x_max
%     abs(x_5) <= x_max
%     abs(x_6) <= x_max
%     abs(x_7) <= x_max
%     abs(x_8) <= x_max
%     abs(x_9) <= x_max
%     abs(x_10) <= x_max
%     abs(x_11) <= x_max
%     abs(u_0) <= u_max
%     abs(u_1) <= u_max
%     abs(u_2) <= u_max
%     abs(u_3) <= u_max
%     abs(u_4) <= u_max
%     abs(u_5) <= u_max
%     abs(u_6) <= u_max
%     abs(u_7) <= u_max
%     abs(u_8) <= u_max
%     abs(u_9) <= u_max
%     abs(u_10) <= u_max
%     norm(u_1 - u_0, inf) <= S
%     norm(u_2 - u_1, inf) <= S
%     norm(u_3 - u_2, inf) <= S
%     norm(u_4 - u_3, inf) <= S
%     norm(u_5 - u_4, inf) <= S
%     norm(u_6 - u_5, inf) <= S
%     norm(u_7 - u_6, inf) <= S
%     norm(u_8 - u_7, inf) <= S
%     norm(u_9 - u_8, inf) <= S
%     norm(u_10 - u_9, inf) <= S
%
% with variables
%      u_0   2 x 1
%      u_1   2 x 1
%      u_2   2 x 1
%      u_3   2 x 1
%      u_4   2 x 1
%      u_5   2 x 1
%      u_6   2 x 1
%      u_7   2 x 1
%      u_8   2 x 1
%      u_9   2 x 1
%     u_10   2 x 1
%      x_1   4 x 1
%      x_2   4 x 1
%      x_3   4 x 1
%      x_4   4 x 1
%      x_5   4 x 1
%      x_6   4 x 1
%      x_7   4 x 1
%      x_8   4 x 1
%      x_9   4 x 1
%     x_10   4 x 1
%     x_11   4 x 1
%
% and parameters
%        A   4 x 4
%        B   4 x 2
%        Q   4 x 4    PSD
%  Q_final   4 x 4    PSD
%        R   2 x 2    PSD
%        S   1 x 1    positive
%    u_max   1 x 1    positive
%      x_0   4 x 1
%    x_max   1 x 1    positive
%  x_ref_1   4 x 1
%  x_ref_2   4 x 1
%  x_ref_3   4 x 1
%  x_ref_4   4 x 1
%  x_ref_5   4 x 1
%  x_ref_6   4 x 1
%  x_ref_7   4 x 1
%  x_ref_8   4 x 1
%  x_ref_9   4 x 1
% x_ref_10   4 x 1
% x_ref_11   4 x 1
%
% Note:
%   - Check status.converged, which will be 1 if optimization succeeded.
%   - You don't have to specify settings if you don't want to.
%   - To hide output, use settings.verbose = 0.
%   - To change iterations, use settings.max_iters = 20.
%   - You may wish to compare with cvxsolve to check the solver is correct.
%
% Specify params.A, ..., params.x_ref_11, then run
%   [vars, status] = csolve(params, settings)
% Produced by CVXGEN, 2020-02-24 13:45:01 -0500.
% CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com.
% The code in this file is Copyright (C) 2006-2017 Jacob Mattingley.
% CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
% applications without prior written permission from Jacob Mattingley.

% Filename: csolve.m.
% Description: Help file for the Matlab solver interface.
