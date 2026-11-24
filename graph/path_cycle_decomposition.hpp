// Source: https://github.com/maspypy/library/blob/main/graph/path_cycle_decomposition.hpp
#include "graph/base.hpp"

// どの点の次数も 2 以下のグラフがあるときに、
// パスの頂点列, サイクルの頂点列
// に分解する
template <typename GT>
pair<vvc<int>, vvc<int>> path_cycle_decomposition(GT& G) {
  static_assert(!GT::is_directed);
  int N = G.N;
  FOR(v, N) assert(G.deg(v) <= 2);

  vc<bool> done(N);
  auto calc_frm = [&](int v) -> vc<int> {
    vc<int> P = {v};
    done[v] = 1;
    while (1) {
      bool ok = 0;
      for (auto&& e : G[P.back()]) {
        if (done[e.to]) continue;
        P.eb(e.to);
        done[e.to] = 1;
        ok = 1;
        break;
      }
      if (!ok) break;
    }
    return P;
  };
  vvc<int> paths, cycs;
  FOR(v, N) {
    if (G.deg(v) == 0) {
      done[v] = 1;
      paths.eb(vc<int>({int(v)}));
    }
    if (done[v] || G.deg(v) != 1) continue;
    paths.eb(calc_frm(v));
  }
  FOR(v, N) {
    if (done[v]) continue;
    cycs.eb(calc_frm(v));
  }
  return {paths, cycs};
}
