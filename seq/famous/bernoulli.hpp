#include "poly/fps_div.hpp"

template <typename mint>
vc<mint> bernoulli_number(int N) {
  int n = N / 2;
  vc<mint> F(n + 1), G(n + 1);
  mint pow = 1;
  FOR(i, n + 1) {
    F[i] = fact_inv<mint>(2 * i) * pow;
    G[i] = fact_inv<mint>(2 * i + 1) * pow;
    pow *= inv<mint>(4);
  }
  F = fps_div<mint>(F, G);
  vc<mint> B(N + 1);
  if (1 <= N) B[1] = -inv<mint>(2);
  FOR(i, n + 1) B[2 * i] = F[i] * fact<mint>(2 * i);
  return B;
}
