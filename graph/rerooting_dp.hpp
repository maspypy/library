
#include "graph/base.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename Data>
struct Rerooting_dp {
  TREE& tree;
  vc<Data> dp_1; // 辺 pv に対して、部分木 v
  vc<Data> dp_2; // 辺 pv に対して、部分木 p
  vc<Data> dp;   // すべての v に対して、v を根とする部分木

  template <typename F1, typename F2, typename F3>
  Rerooting_dp(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit)
      : tree(tree) {
    assert(!tree.G.is_directed());
    build(f_ee, f_ev, f_ve, unit);
  }

  // v を根としたときの full tree
  Data operator[](int v) { return dp[v]; }

  // root を根としたときの部分木 v
  Data get(int root, int v) {
    if (root == v) return dp[v];
    if (!tree.in_subtree(root, v)) { return dp_1[v]; }
    int w = tree.jump(v, root, 1);
    return dp_2[w];
  }

  template <typename F1, typename F2, typename F3>
  void build(F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) {
    int N = tree.G.N;
    dp_1.assign(N, unit);
    dp_2.assign(N, unit);
    dp.assign(N, unit);
    auto& V = tree.V;
    auto& par = tree.parent;

    FOR_R(i, N) {
      int v = V[i];
      auto ch = tree.collect_child(v);
      int n = len(ch);
      vc<Data> Xl(n + 1, unit), Xr(n + 1, unit);
      FOR(i, n) Xl[i + 1] = f_ee(Xl[i], dp_2[ch[i]]);
      FOR_R(i, n) Xr[i] = f_ee(dp_2[ch[i]], Xr[i + 1]);
      FOR(i, n) dp_2[ch[i]] = f_ee(Xl[i], Xr[i + 1]);
      dp[v] = Xr[0];
      dp_1[v] = f_ev(dp[v], v);
      for (auto&& e: tree.G[v]) {
        if (e.to == par[v]) { dp_2[v] = f_ve(dp_1[v], e); }
      }
    }
    {
      int v = V[0];
      dp[v] = f_ev(dp[v], v);
      for (auto&& e: tree.G[v]) dp_2[e.to] = f_ev(dp_2[e.to], v);
    }
    FOR(i, N) {
      int v = V[i];
      for (auto&& e: tree.G[v]) {
        if (e.to == par[v]) continue;
        Data x = f_ve(dp_2[e.to], e);
        for (auto&& f: tree.G[e.to]) {
          if (f.to == par[e.to]) continue;
          dp_2[f.to] = f_ee(dp_2[f.to], x);
          dp_2[f.to] = f_ev(dp_2[f.to], e.to);
        }
        x = f_ee(dp[e.to], x);
        dp[e.to] = f_ev(x, e.to);
      }
    }
  }
};
