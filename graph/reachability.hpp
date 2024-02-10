#pragma once
#include "graph/strongly_connected_component.hpp"

// 有向グラフの到達可能性クエリ。O((N+M)Q/w)。
template <typename GT, typename P>
vc<int> reachability(GT& G, vc<P> query) {
  using U = u64;
  constexpr int W = 64;

  auto [C, comp] = strongly_connected_component(G);

  vc<pair<int, int>> edges;
  for (auto&& e: G.edges) {
    auto a = comp[e.frm], b = comp[e.to];
    assert(a <= b);
    if (a < b) edges.eb(a, b);
  }
  UNIQUE(edges);
  for (auto& [a, b]: query) a = comp[a], b = comp[b];

  int Q = len(query);
  vc<int> ANS(Q);

  vc<int> S;
  vvc<int> QID(C);
  FOR(q, Q) {
    auto [a, b] = query[q];
    if (a >= b) {
      ANS[q] = (a == b);
      continue;
    }
    QID[a].eb(q);
    S.eb(a);
  }

  UNIQUE(S);
  vc<U> dp(C);
  int p = 0;
  for (int l = 0; l < len(S); l += W) {
    int r = min<int>(l + W, len(S));
    fill(dp.begin() + S[l], dp.end(), U(0));
    FOR(i, r - l) { dp[S[l + i]] |= U(1) << i; }
    while (p < len(edges) && edges[p].fi < S[l]) ++p;
    FOR(i, p, len(edges)) { dp[edges[i].se] |= dp[edges[i].fi]; }
    FOR(i, r - l) {
      int s = S[l + i];
      for (auto& qid: QID[s]) {
        int t = query[qid].se;
        ANS[qid] = dp[t] >> i & 1;
      }
    }
  }
  return ANS;
}