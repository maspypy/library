#include "graph/count/count_labeled_undirected.hpp"
#include "poly/fps_log.hpp"

// https://oeis.org/A001187
template <typename mint>
vc<mint> count_labeled_connected(int N) {
  vc<mint> F = count_labeled_undirected<mint>(N);
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  F = fps_log(F);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  return F;
}
