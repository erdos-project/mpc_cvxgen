
# mpc_cvxgen: An Efiicient MPC Solver Based on CVXGEN

This is intended to replace the naive MPC class in Pylot which currently uses a less efficient solver from `cvxpy`. The `cvxgen` version of the solver in class `ModelPredictiveControllerCVXGEN` can speed up the computation by a factor of 100x through directly calling the compiled C library `applysolver.so`.

`ModelPredictiveControllerCVXGEN` is an inherited class of `ModelPredictiveController` and _should_ work out-of-the-box by directly replacing the `ModelPredictiveController` class in the Pyplot MPC operator. Note that due to differences in the solvers from `cvxpy` and `cvxgen`, the exact solutions might differ slightly. However, the overall effectiveness of the control should remain comparable (although this claim needs to be verified numerically).