#include "seq/famous/bernoulli.hpp"

// 2 以上 N 以下の偶数に対して, zeta(n) = c pi^n となる c
// [0,0,1/6,0,1/90,...]
template <typename mint>
vc<mint> riemann_zeta_even(int N) {
  auto B = bernoulli_number<mint>(N);
  mint pow = inv<mint>(4);
  FOR(n, N + 1) {
    pow += pow;
    if (n <= 1 || n & 1) {
      B[n] = 0;
      continue;
    }
    B[n] *= fact_inv<mint>(n);
    B[n] *= pow;
    if (!(n & 2)) B[n] = -B[n];
  }
  return B;
}

// n-th of [0,0,1/6,0,1/90,...]
template <typename mint>
mint single_riemann_zeta_even(int n) {
  assert(n % 2 == 0);
  mint x = single_bernoulli<mint>(n);
  x *= mint(2).pow(n);
  x *= fact_inv<mint>(n);
  if (n % 4 == 0) x = -x;
  x *= inv<mint>(2);
  return x;
}