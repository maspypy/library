#include "flow/bipartite.hpp"

// 比較可能グラフを与える。DAG なだけではダメ。
template <typename GT>
vc<int> maximum_antichain(GT& G) {
  static_assert(GT::is_directed);
  int n = G.N;

  Graph H(n + n);
  for (auto&& e: G.edges) { H.add(e.frm, e.to + n); }
  H.build();
  BipartiteMatching BM(H);
  auto cover = BM.vertex_cover();
  auto match = BM.matching();
  assert(len(cover) == len(match));
  vc<bool> ok(n, 1);
  for (auto&& v: cover) { ok[v % n] = 0; }
  vc<int> antichain;
  FOR(v, n) if (ok[v]) antichain.eb(v);
  for (auto&& e: G.edges) { assert(!ok[e.frm] || !ok[e.to]); }
  return antichain;
}