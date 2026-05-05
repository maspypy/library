
// https://arxiv.org/pdf/1807.04942
// Example 5.
// O(LIM n log n)
template <typename TREE, typename VAL>
vc<VAL> connected_set_knapsack(TREE& tree, vc<int> weight, vc<VAL> val,
                               int LIM) {
  // すべての rooted subtree で ancestor_closed を解く感じのアルゴリズム
  using V = vc<VAL>;

  V ANS(LIM + 1, -infty<VAL>);

  auto dfs = [&](auto& dfs, int v, const V& X, bool upd_ans) -> V {
    assert(len(X) == LIM + 1);
    int heavy = tree.heavy_child(v);
    V Y(LIM + 1, -infty<VAL>);
    if (heavy == -1) {
      FOR(i, LIM + 1) { chmax(Y[i], X[i]); }
      FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]], X[i] + val[v]);
      if (upd_ans) {
        FOR(i, LIM - weight[v] + 1) chmax(ANS[i + weight[v]], X[i] + val[v]);
      }
      return Y;
    }
    auto Z = dfs(dfs, heavy, X, upd_ans);
    auto ch = tree.collect_light(v);

    // not take v.
    FOR(i, LIM + 1) chmax(Y[i], X[i]);

    // take v.
    V cur = move(Z);
    for (int w : ch) {
      cur = dfs(dfs, w, cur, false);
    }
    FOR(i, LIM - weight[v] + 1) chmax(Y[i + weight[v]], cur[i] + val[v]);
    if (upd_ans) {
      FOR(i, LIM - weight[v] + 1) chmax(ANS[i + weight[v]], cur[i] + val[v]);
    }
    return Y;
  };

  FOR(v, tree.N) {
    if (tree.head[v] == v) {
      V X(LIM + 1, -infty<VAL>);
      X[0] = 0;
      dfs(dfs, v, X, true);
    }
  }

  for (auto& x : ANS)
    if (x < 0) x = -infty<VAL>;
  return ANS;
}
