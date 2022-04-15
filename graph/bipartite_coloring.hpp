#pragma once
#include "graph/base.hpp"
#include "my_template.hpp"

pair<int, vi> bipartite_edge_coloring(Graph<ll>& G) {
  auto N = G.N;
  vi deg(N);
  vi ANS(G.M, -1);
  FORIN(e, G.edges) {
    ++deg[e.frm];
    ++deg[e.to];
  }
  ll C = MAX(deg);
  // 頂点, 色 -> 辺番号
  vv(int, TO, N, C, -1);

  FOR(id, G.M) {
    auto const a = G.edges[id].frm, b = G.edges[id].to;
    [&] {
      // a で実現していない色 ca と b で実現していない色 cb をひとつとる。
      int ca = -1, cb = -1;
      FOR(c, C) if (TO[a][c] == -1) {
        ca = c;
        break;
      }
      FOR(c, C) if (TO[b][c] == -1) {
        cb = c;
        break;
      }
      int v = a, w = b, eid = id, cv = ca, cw = cb;
      while (1) {
        ANS[eid] = cv;
        TO[v][cv] = eid;
        TO[w][cw] = -1;
        if (TO[w][cv] == -1) {
          TO[w][cv] = eid;
          break;
        }
        swap(eid, TO[w][cv]);
        auto const& e = G.edges[eid];
        v = w;
        w ^= e.frm ^ e.to;
        swap(cv, cw);
      }
    }();
  }
  return {C, ANS};
}