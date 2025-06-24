#pragma once
#include "graph/strongly_connected_component.hpp"
#include "graph/reverse_graph.hpp"

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

// ANS[v] := count(reachable from v).
// (N,M)=(2e5,4e5): ほぼちょうど 1.5sec. 結構実行時間がぶれる.
// https://codeforces.com/contest/2041/problem/K
vc<int> count_reachable(Graph<int, 1> G) {
  G = reverse_graph(G);
  int N = G.N;
  auto [nc, comp] = strongly_connected_component(G);
  vc<int> sz(nc);
  FOR(v, N) sz[comp[v]]++;

  // sorted pairs
  vc<pair<int, int>> E;
  for (auto& e: G.edges) {
    int a = comp[e.frm], b = comp[e.to];
    if (a != b) E.eb(a, b);
  }
  UNIQUE(E);

  vc<int> ANS(nc);
  int p = 0;
  int idx = 0;
  vc<u128> dp(nc);
  while (p < nc) {
    int k = 0;
    int s = p;
    memset(dp.data() + s, 0, (nc - s) * sizeof(u128));
    while (k < 128 && p < nc) {
      if (sz[p] == 0) ++p;
      if (p == nc) break;
      int m = min(sz[p], 128 - k);
      for (int i = k; i < k + m; ++i) dp[p] |= u128(1) << i;
      sz[p] -= m, k += m;
    }
    while (idx < len(E) && E[idx].fi < s) ++idx;
    FOR(i, idx, len(E)) { dp[E[i].se] |= dp[E[i].fi]; }
    FOR(v, s, nc) { ANS[v] += popcnt(u64(dp[v] >> 64)) + popcnt(u64(dp[v])); }
  }
  ANS = rearrange(ANS, comp);
  return ANS;
}
