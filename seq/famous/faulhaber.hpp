#include "seq/famous/bernoulli.hpp"

// sum_[1,n]i^k=f(n)
template <typename mint>
vc<mint> faulhaber_formula(int k) {
  vc<mint> F = bernoulli_number<mint>(k + 1);
  if (1 <= k) F[1] = inv<mint>(2);
  reverse(all(F));
  F[0] = 0;
  FOR(r, k + 1) { F[k - r + 1] *= fact<mint>(k) * fact_inv<mint>(r) * fact_inv<mint>(k + 1 - r); }
  return F;
}

// sum_[1,n]i^k=f(n)
template <typename mint>
vvc<mint> faulhaber_formula_2d(int n) {
  vc<mint> B = bernoulli_number<mint>(n);
  if (1 <= n) B[1] = inv<mint>(2);
  vvc<mint> ANS(n + 1);
  FOR(k, n + 1) {
    ANS[k].resize(k + 2);
    FOR(j, k + 1) ANS[k][k + 1 - j] = inv<mint>(k + 1) * C<mint>(k + 1, j) * B[j];
  }
  return ANS;
}