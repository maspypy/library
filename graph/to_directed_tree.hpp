#include "graph/base.hpp"

template <typename GT>
Graph<typename GT::cost_type, true> to_directed_tree(GT& G, int root = 0) {
  assert(!GT::is_directed);
  if (!G.is_prepared()) G.build();
  int N = G.N;
  vc<int> par_e(N, -1);
  vc<int> V(N);
  int l = 0, r = 0;
  V[r++] = root;
  while (l < r) {
    int v = V[l++];
    for (auto&& e: G[v]) {
      if (e.id != par_e[v]) {
        par_e[e.to] = e.id;
        V[r++] = e.to;
      }
    }
  }
  Graph<typename GT::cost_type, true> H(N);
  FOR(v, N) {
    if (v == root) continue;
    assert(par_e[v] != -1);
    int eid = par_e[v];
    auto& e = G.edges[eid];
    int p = e.frm ^ e.to ^ v;
    H.add(p, v, e.cost, e.id);
  }
  H.build();
  return H;
}
