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