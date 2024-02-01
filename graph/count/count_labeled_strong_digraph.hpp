#include "poly/fps_inv.hpp"
#include "poly/fps_log.hpp"

// https://oeis.org/A003030
template <typename mint>
vc<mint> count_labeled_strong_digraph(int N) {
  vc<mint> F(N + 1, 1);
  // 2^n(n-1)倍したあと 2^nC2 で割る
  mint pow = 1;
  FOR(i, 1, N + 1) F[i] = F[i - 1] * pow, pow += pow;
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  F = fps_inv<mint>(F);
  pow = 1;
  mint c = 1;
  FOR(i, N + 1) F[i] *= c, c *= pow, pow += pow;
  F = fps_log(F);
  FOR(i, N + 1) F[i] = -F[i] * fact<mint>(i);
  return F;
}