
#include "graph/tree.hpp"

// https://arxiv.org/pdf/1807.04942
// Example 2. v を選ぶならば par[v] も選ぶ
// // O(LIM n)
template <typename TREE, typename VAL>
vc<VAL> ancestor_closed_set_knapsack(TREE& tree, vc<int> weight, vc<VAL> val,
                                     int LIM) {
  using V = vc<VAL>;

  auto dfs = [&](auto& dfs, int v, const V& X) -> V {
    assert(len(X) == LIM + 1);
    int heavy = tree.heavy_child(v);
    V Y(LIM + 1, -infty<VAL>);
    if (heavy == -1) {
      FOR(i, LIM + 1) { chmax(Y[i], X[i]); }
      FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]], X[i] + val[v]);
      return Y;
    }
    auto Z = dfs(dfs, heavy, X);
    auto ch = tree.collect_light(v);

    // not take v.
    FOR(i, LIM + 1) chmax(Y[i], X[i]);

    // take v.
    V cur = move(Z);
    for (int w : ch) {
      cur = dfs(dfs, w, cur);
    }
    FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]], cur[i] + val[v]);
    return Y;
  };

  V X(LIM + 1, -infty<VAL>);
  X[0] = 0;
  V ANS = dfs(dfs, 0, X);
  for (auto& x : ANS)
    if (x < 0) x = -infty<VAL>;
  return ANS;
}