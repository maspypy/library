#include "graph/count_C3_C4.hpp"

// 各 v に対して、v を始点とする P3, P4 を数える
// https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_h
template <typename GT>
pair<vi, vi> count_P3_P4_pointwise(GT& G) {
  int N = G.N;
  auto deg = G.deg_array();
  auto [C3, C4] = count_C3_C4_pointwise(G);

  vi P2(N), P3(N), P4(N);
  using ARR = array<ll, 5>;
  vc<ARR> path(N, {1, 0, 0, 0, 0});
  FOR(v, N) path[v][1] = deg[v];

  FOR(v, N) {
    for (auto&& e: G[v]) P2[v] += deg[e.to] - 1;
  }

  FOR(v, N) {
    for (auto&& e: G[v]) { P3[v] += P2[e.to] - (deg[v] - 1); }
    P3[v] -= C3[v] * 2;
  }

  FOR(v, N) {
    for (auto&& e: G[v]) { P4[v] += P3[e.to]; }
    P4[v] -= C4[v] * 2;
    P4[v] -= C3[v] * 2 * (deg[v] - 3);
    P4[v] -= P2[v] * (deg[v] - 1);
  }
  return {P3, P4};
}