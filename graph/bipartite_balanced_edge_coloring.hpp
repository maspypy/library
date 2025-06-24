#include "graph/bipartite_edge_coloring.hpp"

// 辺を K 色で塗る. 各点のまわりで色が均等（max-min <= 1）にせよ.
// return : color[eid].
// https://codeforces.com/contest/212/problem/A
vc<int> bipartite_balanced_edge_coloring(Graph<int, 0> G, int K) {
  int N = G.N, M = G.M;
  vc<int> A, B;
  vc<int> cnt(N);
  vc<int> now(N);
  int nxt = 0;

  auto get = [&](int v) -> int {
    if (cnt[v] % K == 0) { now[v] = nxt++; }
    cnt[v]++;
    return now[v];
  };
  for (auto& e: G.edges) {
    int a = e.frm, b = e.to;
    a = get(a), b = get(b);
    A.eb(a), B.eb(b);
  }
  Graph<int, 0> H(nxt);
  FOR(i, M) H.add(A[i], B[i]);
  H.build();
  return bipartite_edge_coloring(H).se;
}
