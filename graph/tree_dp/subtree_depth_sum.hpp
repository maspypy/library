
#include "graph/tree_dp/rerooting_dp.hpp"

// sum_v dist(root, v)
template <typename TREE, typename WT = ll>
struct SubTree_DepthSum {
  // num_point, dist_sum
  using Data = pair<int, WT>;
  TREE& tree;
  vc<Data> dp, dp_1, dp_2;

  SubTree_DepthSum(TREE& tree) : tree(tree) {
    int N = tree.N;
    Data unit = {0, 0};
    auto f_ee = [&](Data A, Data B) -> Data {
      return {A.fi + B.fi, A.se + B.se};
    };
    auto f_ev = [&](Data A, int v) -> Data { return {A.fi + 1, A.se}; };
    auto f_ve = [&](Data A, const auto& e) -> Data {
      return {A.fi, A.se + A.fi * e.cost};
    };

    Rerooting_dp<decltype(tree), Data> DP(tree, f_ee, f_ev, f_ve, unit);
    dp = DP.dp, dp_1 = DP.dp_1, dp_2 = DP.dp_2;
  }

  // (cnt, sum)
  // v を根としたときの full tree
  pair<int, WT> operator[](int v) { return dp[v]; }

  // (cnt, sum)
  // root を根としたときの部分木 v
  pair<int, WT> get(int root, int v) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) { return dp_1[v]; }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }
};