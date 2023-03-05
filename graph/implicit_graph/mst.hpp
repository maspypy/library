#include "ds/unionfind/unionfind.hpp"

// Brouvka
// 陽にグラフを作らず、何らかのデータ構造で未訪問の行き先を探す想定。
// find_unused(v)：unused なうちで、v と最小コストで結べる点を探す。
// pair<int,COST> なければ {-1,*} を返すこと。
template <typename COST, typename F0, typename F1, typename F2>
vc<tuple<int, int, COST>> implicit_graph_mst(int N, F0 set_used, F1 set_unused,
                                     F2 find_unused) {
  using edge = tuple<int, int, COST>;
  UnionFind uf(N);
  vc<edge> res;
  while (1) {
    bool upd = 0;
    vvc<int> comp(N);
    vc<edge> cand(N, {-1, -1, -1});
    FOR(v, N) comp[uf[v]].eb(v);
    FOR(v, N) if (uf[v] == v) {
      for (auto&& x: comp[v]) { set_used(x); }
      for (auto&& x: comp[v]) {
        auto [y, cost] = find_unused(x);
        if (y == -1) continue;
        auto [a, b, c] = cand[v];
        if (a == -1 || cost < c) { cand[v] = {x, y, cost}; }
      }
      for (auto&& x: comp[v]) { set_unused(x); }
    }
    FOR(v, N) if (uf[v] == v) {
      auto [a, b, c] = cand[v];
      if (a == -1) continue;
      upd = 1;
      if (uf.merge(a, b)) res.eb(a, b, c);
    }
    if (!upd) break;
  }
  return res;
}