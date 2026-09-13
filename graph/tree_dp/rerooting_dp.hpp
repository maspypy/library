#include "graph/tree.hpp"

template <typename TREE, typename Data>
struct Rerooting_DP {
  TREE& tree;

  // virtual tree at v, downward
  vc<Data> dp_down;
  // virtual tree at parent[c], consisting of children before c
  vc<Data> dp_prefix;
  // virtual tree at v, upward
  vc<Data> dp_up;
  // full tree rooted at v
  vc<Data> dp;

  template <typename F1, typename F2, typename F3>
  Rerooting_DP(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data id)
      : tree(tree) {
    build(f_ee, f_ev, f_ve, id);
  }

  Data operator[](int v) const { return dp[v]; }

  template <typename F1, typename F2, typename F3>
  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data id) {
    int N = tree.N;
    dp_down.assign(N, id);
    dp_prefix.assign(N, id);
    dp_up.assign(N, id);
    dp.assign(N, id);

    // dp_down, dp_prefix
    FOR_R(i, N) {
      int v = tree.V[i];
      Data X = id;
      for (int c : tree.collect_child(v)) {
        dp_prefix[c] = X;
        Data Y = f_ev(dp_down[c], c);
        Y = f_ve(Y, c, v);
        X = f_ee(X, Y);
      }
      dp_down[v] = X;
    }

    // dp_up, dp
    int root = tree.V[0];
    dp_up[root] = id;

    FOR(i, N) {
      int v = tree.V[i];
      auto ch = tree.collect_child(v);

      Data X = dp_up[v];
      FOR_R(k, len(ch)) {
        int c = ch[k];

        // v -> c に渡す親側
        Data Y = f_ee(dp_prefix[c], X);
        Y = f_ev(Y, v);
        dp_up[c] = f_ve(Y, v, c);

        // c の寄与を suffix 側に追加
        Y = f_ev(dp_down[c], c);
        Y = f_ve(Y, c, v);
        X = f_ee(Y, X);
      }

      dp[v] = f_ev(X, v);
    }
  }
};