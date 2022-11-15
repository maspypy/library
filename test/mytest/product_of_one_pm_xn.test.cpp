#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/product_of_one_minus_xn.hpp"
#include "poly/product_of_one_plus_xn.hpp"

using mint = modint998;

vc<int> gen(int N, int M) {
  vc<int> A(M);
  FOR(i, M) { A[i] = RNG(0, N + 2); }
  return A;
}

void test() {
  FOR(N, 100) FOR(M, 100) {
    vc<int> A = gen(N, M);
    auto F = product_of_one_minus_xn<mint>(A, N);
    auto G = product_of_one_plus_xn<mint>(A, N);

    vc<mint> f(N + 1), g(N + 1);
    f[0] = 1, g[0] = 1;
    for (auto&& a: A) {
      FOR_R(i, N + 1) {
        if (i + a <= N) {
          f[i + a] -= f[i];
          g[i + a] += g[i];
        }
      }
    }
    assert(F == f);
    assert(G == g);
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
