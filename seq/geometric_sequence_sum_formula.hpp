#include "poly/fps_inv.hpp"

// r != 1 とする. sum_{i=0}^{n-1}i^kr^i = c + r^n f(n) と書ける. return : c, f
// https://codeforces.com/contest/1677/problem/F
template <typename mint>
pair<mint, vc<mint>> geometric_sequence_sum_formula(mint r, int K) {
  assert(r != 1);
  vc<mint> F(K + 1);
  F[0] = 1;
  FOR(i, K + 1) F[i] -= r * fact_inv<mint>(i);
  F = fps_inv<mint>(F);
  mint c = F[K] * fact<mint>(K);
  reverse(all(F));
  FOR(k, K + 1) F[k] *= -fact_inv<mint>(k) * fact<mint>(K);
  return {c, F};
}
