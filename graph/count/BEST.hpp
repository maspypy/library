#include "graph/base.hpp"
#include "linalg/blackbox/det.hpp"
#include "linalg/det.hpp"

/*
ひとつ選んだ辺から始めて全ての辺を通る closed walk を数える.
多重辺は vc<int>(eid) で渡す，なければすべて 1. e.cost は参照しない.
辺はラベル付きで考える. 多重辺を同一視する場合などは後で階乗で割ること.
O(N^2+NM) （ + 最後に重複度の階乗をかける）．
*/
template <typename mint, bool sparse, typename GT>
mint BEST_theorem(GT G, vc<int> edge_multiplicity = {}) {
  static_assert(GT::is_directed);
  int N = G.N, M = G.M;
  if (M == 0) return 0;
  if (edge_multiplicity.empty()) edge_multiplicity.assign(M, 1);
  vc<int> vs;
  for (auto& e: G.edges) {
    if (edge_multiplicity[e.id] == 0) continue;
    vs.eb(e.frm), vs.eb(e.to);
  }

  UNIQUE(vs);
  G = G.rearrange(vs, true);
  N = G.N;

  vc<int> indeg(N), outdeg(N);
  if constexpr (sparse) {
    vc<tuple<int, int, mint>> mat;
    for (auto& e: G.edges) {
      int a = e.frm, b = e.to, x = edge_multiplicity[e.id];
      outdeg[a] += x, indeg[b] += x;
      if (a < N - 1 && b < N - 1) mat.eb(a, b, -x);
      if (a < N - 1) mat.eb(a, a, x);
    }
    FOR(v, N) if (indeg[v] != outdeg[v]) return 0;

    auto apply = [&](vc<mint> A) -> vc<mint> {
      vc<mint> B(N - 1);
      for (auto& [a, b, c]: mat) B[b] += A[a] * c;
      return B;
    };
    mint d = blackbox_det<mint>(N - 1, apply);
    for (auto& x: outdeg) { d *= fact<mint>(x - 1); }
    return d;
  } else {
    // dense
    vv(mint, mat, N - 1, N - 1);
    for (auto& e: G.edges) {
      int a = e.frm, b = e.to, x = edge_multiplicity[e.id];
      outdeg[a] += x, indeg[b] += x;
      if (a < N - 1 && b < N - 1) mat[a][b] -= x;
      if (a < N - 1) mat[a][a] += x;
    }
    FOR(v, N) if (indeg[v] != outdeg[v]) return 0;
    mint d = det(mat);
    for (auto& x: outdeg) { d *= fact<mint>(x - 1); }
    return d;
  }
}
