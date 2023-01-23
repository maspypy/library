#include "graph/base.hpp"
#include "ds/fastset.hpp"

// 辞書順最小の toposort を返す
template <typename GT>
vc<int> toposort(GT& G) {
  assert(G.is_prepared() && G.is_directed());
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
