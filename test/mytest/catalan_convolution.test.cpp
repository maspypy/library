#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution.hpp"
#include "seq/famous/catalan_convolution.hpp"

using mint = modint998;

void test() {
  ll N = 10;
  vc<mint> A(N);
  A[0] = 1;
  vc<mint> B(N);
  FOR(i, N) B[i] = C<mint>(i + i, i) * inv<mint>(1 + i);
  FOR(k, 10) {
    FOR(n, N) { assert(A[n] == catalan_convolution<mint>(k, n)); }
    A = convolution<mint>(A, B);
    A.resize(N);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}