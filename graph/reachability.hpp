#pragma once
#include "graph/strongly_connected_component.hpp"

// 有向グラフの到達可能性クエリ。O((N+M)Q/w)。
template <typename GT, typename P>
vc<int> reachability(GT& G, vc<P> query) {
  auto [C, comp] = strongly_connected_component(G);
  Graph<int, 1> DAG(C);
  for (auto&& e: G.edges) {
    auto a = comp[e.frm], b = comp[e.to];
    assert(a <= b);
    if (a < b) DAG.add(a, b);
  }
  DAG.build();

  int Q = len(query);
  vc<u64> dp(C);
  vc<int> res(Q);
  for (int l = 0; l < Q; l += 64) {
    int r = min(l + 64, Q);
    fill(all(dp), u64(0));

    FOR3(qid, l, r) {
      auto v = comp[query[qid].fi];
      dp[v] |= u64(1) << (qid - l);
    }
    FOR(v, C) for (auto&& e: DAG[v]) { dp[e.to] |= dp[v]; }
    FOR3(qid, l, r) {
      auto v = comp[query[qid].se];
      if (dp[v] & (u64(1) << (qid - l))) res[qid] = 1;
    }
  }
  return res;
}