#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"

#include "mod/modint.hpp"
#include "poly/typical_divide_conquer.hpp"

using mint = modint998;
using poly = vc<mint>;

poly gen(int d) {
  poly f(d + 1);
  FOR(i, d + 1) f[i] = RNG(0, mint::get_mod());
  return f;
}

void test() {
  FOR(N, 10) {
    FOR(FD, 10) {
      vc<poly> A(N), B(N);
      FOR(i, N) {
        A[i] = gen(RNG(0, 5));
        B[i] = gen(RNG(0, 5));
      }
      poly f = gen(FD);
      vc<poly> prod(N);
      FOR(i, N) {
        poly F = f;
        FOR(j, i) F = convolution(F, A[j]);
        FOR(j, i + 1, N) F = convolution(F, B[j]);
        prod[i] = F;
      }
      Typical_Divide_Conquer<mint> X(N);
      FOR(i, N - 1) X.set_L(i, A[i]);
      FOR(i, 1, N) X.set_R(i, B[i]);
      FOR(K, 50) {
        auto ANS = X.calc(K, f);
        vc<mint> naive(N);
        FOR(i, N) naive[i] = (K < len(prod[i]) ? prod[i][K] : mint(0));
        assert(ANS == naive);
      }
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}