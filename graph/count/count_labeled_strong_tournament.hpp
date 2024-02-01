#include "poly/fps_inv.hpp"

// https://oeis.org/A054946
template <typename mint>
vc<mint> count_labeled_strong_tournament(int N) {
  vc<mint> F(N + 1, 1);
  mint pow = 1;
  FOR(n, 1, N + 1) F[n] = F[n - 1] * pow, pow += pow;
  FOR(n, N + 1) F[n] *= fact_inv<mint>(n);
  F = fps_inv(F);
  F[0] = 0;
  FOR(n, N + 1) F[n] = -F[n] * fact<mint>(n);
  return F;
}
