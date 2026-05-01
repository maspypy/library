#pragma once

#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"

// 現在の辺重み偶奇で二部グラフ頂点彩色, 二部でなかった場合には empty
// weight_one=true: 辺重みを 1 とする
template <typename GT>
vc<int> bipartite_vertex_coloring(GT& G, bool weight_one = false) {
  assert(!GT::is_directed);
  assert(G.is_prepared());

  int n = G.N;
  UnionFind uf(2 * n);
  for (auto&& e : G.edges) {
    int u = e.frm, v = e.to, c = (weight_one ? 1 : e.cost);
    if (c % 2 == 0) {
      uf.merge(u, v), uf.merge(u + n, v + n);
    } else {
      uf.merge(u + n, v), uf.merge(u, v + n);
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
