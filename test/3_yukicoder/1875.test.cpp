#define PROBLEM "https://yukicoder.me/problems/no/1875"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "poly/poly_taylor_shift.hpp"
#include "poly/product_of_pow_of_linear.hpp"
#include "poly/composition_f_ex.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  using poly = vc<mint>;
  vc<mint> A(N), B(N);
  vi C(N);
  FOR(i, N) {
    LL(a, b, c);
    A[i] = a, B[i] = b, C[i] = c;
  }
  poly f = product_of_pow_of_linear(M, A, B, C);
  // f(e^x-1) を求めたい
  f = poly_taylor_shift(f, mint(-1));
  f = composition_f_ex(f);
  FOR(i, M + 1) f[i] *= fact<mint>(i);
  FOR(i, 1, M + 1) print(f[i]);
}

signed main() {
  solve();
  return 0;
}