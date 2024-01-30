#include "poly/fps_inv.hpp"

// https://oeis.org/A003024
template <typename mint>
vc<mint> count_labeled_dag(int N) {
  vc<mint> F(N + 1, 1);
  mint pow = 1;
  FOR(n, 1, N + 1) F[n] = F[n - 1] * pow, pow *= inv<mint>(2);
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  FOR(i, N + 1) if (i % 2 == 1) F[i] = -F[i];

  F = fps_inv(F);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  mint c = 1;
  pow = 1;
  FOR(i, N + 1) F[i] *= c, c *= pow, pow += pow;
  return F;
}