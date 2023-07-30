#include "graph/reverse_graph.hpp"

// parent (idom) の列を返す. -1 if unreachable.
template <typename GT>
vc<int> dominator_tree(GT& G, int root) {
  assert(G.is_directed());
  const int N = G.N;

  vc<int> par(N, -1), ord(N, -1), V;
  V.reserve(N);
  auto dfs = [&](auto& dfs, int v) -> void {
    ord[v] = len(V);
    V.eb(v);
    for (auto&& e: G[v]) {
      if (ord[e.to] == -1) par[e.to] = v, dfs(dfs, e.to);
    }
  };
  dfs(dfs, root);

  auto RG = reverse_graph(G);

  vc<int> sdom(N, -1);
  FOR(v, N) sdom[v] = v;
  vc<int> mi = sdom;
  vc<int> anc(N, -1);
  vc<int> us(N);

  auto find = [&](auto& find, int v) -> int {
    auto& a = anc[v];
    if (a == -1) return v;
    int b = find(find, a);
    if (ord[sdom[mi[a]]] < ord[sdom[mi[v]]]) mi[v] = mi[a];
    return anc[v] = b;
  };

  vvc<int> bucket(N);

  FOR_R(i, 1, len(V)) {
    int w = V[i];
    for (auto&& e: RG[w]) {
      int v = e.to;
      if (ord[v] == -1) continue;
      find(find, v);
      if (ord[sdom[mi[v]]] < ord[sdom[w]]) sdom[w] = sdom[mi[v]];
    }
    bucket[sdom[w]].eb(w);

    for (auto&& v: bucket[par[w]]) { find(find, v), us[v] = mi[v]; }
    bucket[par[w]].clear();
    anc[w] = par[w];
  }
  vc<int> idom(N, -1);
  FOR(i, 1, len(V)) {
    int w = V[i];
    idom[w] = (sdom[w] == sdom[us[w]] ? sdom[w] : idom[us[w]]);
  }
  return idom;
}