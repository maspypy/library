#include "graph/tree.hpp"

// https://arxiv.org/pdf/1807.04942
// Example 1.
// O(LIM n^{1.59})
template <typename TREE, typename VAL>
vc<VAL> independent_set_knapsack(TREE& tree, vc<int> weight, vc<VAL> val,
                                 int LIM) {
  using V = vc<VAL>;
  // return: ng, ok
  auto dfs = [&](auto& dfs, int v, const V& X) -> array<V, 2> {
    assert(len(X) == LIM + 1);
    int heavy = tree.heavy_child(v);
    array<V, 2> Y = {V(LIM + 1, -infty<VAL>), V(LIM + 1, -infty<VAL>)};
    if (heavy == -1) {
      FOR(i, LIM + 1) {
        chmax(Y[0][i], X[i]);
        chmax(Y[1][i], X[i]);
      }
      FOR(i, LIM - weight[v] + 1) chmax(Y[1][i + weight[v]], X[i] + val[v]);
      return Y;
    }
    auto Z = dfs(dfs, heavy, X);
    auto ch = tree.collect_light(v);

    // not take v.
    {
      V cur = Z[1];
      for (int w : ch) {
        array<V, 2> T = dfs(dfs, w, cur);
        cur = move(T[1]);
      }
      FOR(i, LIM + 1) chmax(Y[0][i], cur[i]), chmax(Y[1][i], cur[i]);
    }

    // take v.
    {
      V cur = Z[0];
      for (int w : ch) {
        array<V, 2> T = dfs(dfs, w, cur);
        cur = move(T[0]);
      }
      FOR(i, LIM - weight[v] + 1) chmax(Y[1][i + weight[v]], cur[i] + val[v]);
    }
    return Y;
  };

  V X(LIM + 1, -infty<VAL>);
  X[0] = 0;
  V ANS = dfs(dfs, 0, X)[1];
  for (auto& x : ANS)
    if (x < 0) x = -infty<VAL>;
  return ANS;
}