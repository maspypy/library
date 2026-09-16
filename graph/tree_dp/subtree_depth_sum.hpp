
#include "graph/tree_dp/rerooting_dp.hpp"

// sum_v dist(root, v)
template <typename TREE, typename WT = ll>
struct Subtree_Depth_Sum {
  // num_point, dist_sum
  using Data = pair<int, WT>;
  TREE& tree;
  vc<Data> dp, dp_1, dp_2;

  Subtree_Depth_Sum(TREE& tree) : tree(tree) {
    Data id = {0, 0};
    auto f_ee = [&](Data A, Data B) -> Data {
      return {A.fi + B.fi, A.se + B.se};
    };
    auto f_ev = [&](Data A, int) -> Data { return {A.fi + 1, A.se}; };
    auto f_ve = [&](Data A, int r, int nxt_r) -> Data {
      WT x = abs(tree.depth_weight[r] - tree.depth_weight[nxt_r]);
      return {A.fi, A.se + A.fi * x};
    };

    Rerooting_DP<TREE, Data> DP(tree, f_ee, f_ev, f_ve, id);
    dp = DP.dp, dp_1 = DP.dp_subtree, dp_2 = DP.dp_parent;
  }

  // (cnt, sum)
  // v を根としたときの full tree
  pair<int, WT> operator[](int v) { return dp[v]; }

  // (cnt, sum)
  // root を根としたときの部分木 v
  pair<int, WT> get(int v, int root) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) {
      return dp_1[v];
    }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }
};
