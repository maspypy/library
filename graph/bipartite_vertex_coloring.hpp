#pragma once

#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"

// 辺重み 0, 1 で二部グラフ頂点彩色, 二部でなかった場合には empty
template <typename GT>
vc<int> bipartite_vertex_coloring(GT& G) {
  assert(!GT::is_directed);
  assert(G.is_prepared());

  int n = G.N;
  UnionFind uf(2 * n);
  for (auto&& e : G.edges) {
    int u = e.frm, v = e.to;
    if (e.cost == 1) {
      uf.merge(u + n, v), uf.merge(u, v + n);
    } else {
      uf.merge(u, v), uf.merge(u + n, v + n);
    }
  }

  vc<int> color(2 * n, -1);
  FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {
    color[uf[v]] = 0;
    color[uf[v + n]] = 1;
  }
  FOR(v, n) color[v] = color[uf[v]];
  color.resize(n);
  FOR(v, n) if (uf[v] == uf[v + n]) return {};
  return color;
}
