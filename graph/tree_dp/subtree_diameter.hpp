#include "graph/tree_dp/rerooting_dp.hpp"

// https://codeforces.com/problemset/problem/1725/J
template <typename TREE, typename WT>
struct Subtree_Diameter {
  struct Data {
    // 今まで見つけた直径距離、端点
    WT diam;
    int left, right;
    // 根から出ている最大パスの、長さ、端点
    WT path;
    int end;
  };

  TREE& tree;
  vc<tuple<int, int, WT>> dp, dp_1, dp_2;

  Subtree_Diameter(TREE& tree) : tree(tree) {
    int N = tree.N;
    Data id = {-1, -1, -1, -1, -1};
    auto f_ee = [&](Data A, Data B) -> Data {
      if (A.diam == -1) return B;
      if (B.diam == -1) return A;
      if (A.diam < B.diam) swap(A, B);
      if (chmax(A.diam, A.path + B.path)) {
        A.left = A.end, A.right = B.end;
      }
      if (chmax(A.path, B.path)) A.end = B.end;
      return A;
    };
    auto f_ev = [&](Data A, int v) -> Data {
      if (A.diam == -1) {
        A.diam = 0, A.left = v, A.right = v, A.path = 0, A.end = v;
      }
      return A;
    };
    auto f_ve = [&](Data A, int r, int nxt_r) -> Data {
      A.path += abs(tree.depth_weight[r] - tree.depth_weight[nxt_r]);
      if (chmax(A.diam, A.path)) {
        A.left = nxt_r, A.right = A.end;
      }
      return A;
    };

    Rerooting_DP<TREE, Data> DP(tree, f_ee, f_ev, f_ve, id);
    dp.resize(N), dp_1.resize(N), dp_2.resize(N);
    FOR(v, N) {
      dp[v] = {DP.dp[v].left, DP.dp[v].right, DP.dp[v].diam};
      dp_1[v] = {
          DP.dp_subtree[v].left, DP.dp_subtree[v].right, DP.dp_subtree[v].diam};
      dp_2[v] = {
          DP.dp_parent[v].left, DP.dp_parent[v].right, DP.dp_parent[v].diam};
    }
  }

  // (u, v, diam)
  // v を根としたときの full tree
  tuple<int, int, WT> operator[](int v) { return dp[v]; }

  // (u, v, diam)
  // root を根としたときの部分木 v
  tuple<int, int, WT> get(int v, int root) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) {
      return dp_1[v];
    }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }
};