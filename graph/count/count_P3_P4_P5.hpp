#include "graph/count/count_C3_C4.hpp"

// 各 v に対して、v を始点とする P4, P5, P5 を数える（頂点数 3, 4, 5）
// simple graph を仮定している
template <typename GT>
tuple<vi, vi, vi> count_P3_P4_P5_pointwise(GT& G) {
  static_assert(!GT::is_directed);
  int N = G.N;
  auto deg = G.deg_array();
  auto [C3, C4] = count_C3_C4_pointwise(G);

  vi P3(N), P4(N), P5(N);

  FOR(v, N) {
    for (auto&& e: G[v]) {
      if (e.frm == e.to) continue;
      P3[v] += deg[e.to] - 1;
    }
  }

  FOR(v, N) {
    for (auto&& e: G[v]) {
      if (e.frm == e.to) continue;
      P4[v] += P3[e.to] - (deg[v] - 1);
    }
    P4[v] -= C3[v] * 2;
  }
  FOR(v, N) {
    for (auto&& e: G[v]) {
      if (e.frm == e.to) continue;
      P5[v] += P4[e.to];
    }
    P5[v] -= C4[v] * 2;
    P5[v] -= C3[v] * 2 * (deg[v] - 3);
    P5[v] -= P3[v] * (deg[v] - 1);
  }
  return {P3, P4, P5};
}