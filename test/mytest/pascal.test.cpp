#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "mod/modint.hpp"
#include "linalg/implicit_matrix/pascal.hpp"

using mint = modint998;

vc<mint> gen(int N) {
  int mod = mint::get_mod();
  vc<mint> f(N);
  FOR(i, N) f[i] = RNG(mod);
  return f;
}

vc<mint> pascal_1_naive(vc<mint> f) {
  int N = len(f);
  vc<mint> g(N);
  FOR(i, N) FOR(j, N) if (i >= j) g[i] += C<mint>(i, j) * f[j];
  return g;
}

vc<mint> pascal_2_naive(vc<mint> f) {
  int N = len(f);
  vc<mint> g(N);
  FOR(i, N) FOR(j, N) if (i <= j) g[i] += C<mint>(j, i) * f[j];
  return g;
}

void test_1() {
  FOR(N, 1, 100) {
    vc<mint> f = gen(N);
    vc<mint> g1 = pascal_1<mint>(f, 0);
    vc<mint> g2 = pascal_1_naive(f);
    assert(g1 == g2);
    vc<mint> h = pascal_1<mint>(g1, 1);
    assert(f == h);
  }
}

void test_2() {
  FOR(N, 1, 100) {
    vc<mint> f = gen(N);
    vc<mint> g1 = pascal_2<mint>(f, 0);
    vc<mint> g2 = pascal_2_naive(f);
    assert(g1 == g2);
    vc<mint> h = pascal_2<mint>(g1, 1);
    assert(f == h);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_1();
  test_2();
  solve();

  return 0;
}