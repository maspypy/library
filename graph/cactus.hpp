// Source: https://github.com/maspypy/library/blob/main/graph/cactus.hpp

#include "ds/csr.hpp"

// block の index に頂点列が入る
CSR<int> get_cactus_cycles(
    Graph<int, 0>& G, Graph<int, 0>& BCT, Tree<Graph<int, 0>>& tree) {
  CSR<pair<int, int>> es(BCT.N);
  CSR<int> cs(BCT.N);
  for (auto& e : G.edges) {
    int a = e.frm, b = e.to;
    int k = tree.jump(a, b, 1);
    es.add(k, {a, b});
  }
  es.build();
  vc<int> SM(G.N);

  vc<pair<int, int>> E;
  vc<int> C;
  FOR(k, G.N, BCT.N) {
    E.clear();
    for (auto& [a, b] : es[k]) E.eb(a, b);
    if (len(E) == 1) continue;
    for (auto& [a, b] : E) SM[a] += b, SM[b] += a;
    C.clear();
    C.eb(E[0].fi);
    C.eb(E[0].se);
    while (C.back() != C[0]) {
      int a = C[len(C) - 2], b = C[len(C) - 1];
      C.eb(SM[b] - a);
    }
    POP(C);
    for (int v : C) cs.add(k, v);
    for (auto& [a, b] : E) SM[a] -= b, SM[b] -= a;
  }
  cs.build();
  return cs;
}