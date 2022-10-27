#include "mod/powertable.hpp"
#include "poly/convolution.hpp"

// Eulerian number
// sum n^dx^n = A_d(x) / (1-x)^{d+1} となる d 次多項式の係数列
template <typename mint>
vvc<mint> eulerian_number_2d(int N, int K) {
  vv(mint, A, N + 1, K + 1);
  A[0][0] = mint(1);
  FOR(d, N) FOR(k, 1, K + 1) {
    A[d + 1][k] = mint(k) * A[d][k] + mint(d - k + 2) * A[d][k - 1];
  }
  return A;
}

template <typename mint>
vc<mint> eulerian_number_n(int n) {
  vc<mint> f = powertable_2<mint>(n, n);
  vc<mint> g(n + 1);
  FOR(k, n + 1) g[k] = C<mint>(n + 1, k);
  FOR(k, 1, n + 1, 2) g[k] = -g[k];
  f = convolution(f, g);
  f.resize(n + 1);
  return f;
}