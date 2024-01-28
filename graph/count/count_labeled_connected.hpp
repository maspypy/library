#include "poly/fps_log.hpp"

template <typename mint>
vc<mint> count_labeled_connected(int N) {
  vc<mint> F(N + 1);
  mint pow = 1;
  F[0] = 1;
  FOR(n, 1, N + 1) { F[n] = F[n - 1] * pow, pow += pow; }
  // F: 任意の labeled graph
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  F = fps_log(F);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  return F;
}