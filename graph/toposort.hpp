#include "graph/base.hpp"
#include "ds/fastset.hpp"

// 辞書順最小の toposort を返す
template <typename GT>
vc<int> toposort(GT& G) {
  static_assert(GT::is_directed);
  assert(G.is_prepared());
  const int N = G.N;
  auto [indeg, outdeg] = G.deg_array_inout();
  FastSet que(N);
  vc<int> V;
  FOR(v, N) if (indeg[v] == 0) que.insert(v);
  while (1) {
    int v = que.next(0);
    if (v == N) break;
    que.erase(v), V.eb(v);
    for (auto&& e: G[v]) {
      if (--indeg[e.to] == 0) que.insert(e.to);
    }
  }
  return (len(V) < N ? vc<int>{} : V);
}

// inv_perm=true: inv perm が辞書最小（各インデックスの現れる場所の列が最小）
template <typename GT>
vc<int> lex_min_toposort(GT& G, bool inv_perm = false) {
  static_assert(GT::is_directed);
  assert(G.is_prepared());
  const int N = G.N;
  if (inv_perm) {
    GT H(N);
    for (auto& e: G.edges) H.add(N - 1 - e.to, N - 1 - e.frm);
    H.build();
    auto V = lex_min_toposort(H, false);
    reverse(all(V));
    for (auto& x: V) x = N - 1 - x;
    return V;
  }
  auto [indeg, outdeg] = G.deg_array_inout();
  FastSet que(N);
  vc<int> V;
  FOR(v, N) if (indeg[v] == 0) que.insert(v);
  while (1) {
    int v = que.next(0);
    if (v == N) break;
    que.erase(v), V.eb(v);
    for (auto&& e: G[v]) {
      if (--indeg[e.to] == 0) que.insert(e.to);
    }
  }
  return (len(V) < N ? vc<int>{} : V);
}
