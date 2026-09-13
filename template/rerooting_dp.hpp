// template/rerooting_dp.hpp
struct Data {};
Data id = {};
auto f_ee = [&](const Data &x, const Data &y) -> Data {};
auto f_ev = [&](const Data &x, int v) -> Data {};
auto f_ve = [&](const Data &x, int r, int nxt_r) -> Data { return x; };
Rerooting_DP<decltype(tree), Data> dp(tree, f_ee, f_ev, f_ve, id);
