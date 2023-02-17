#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "mod/modint.hpp"
#include "poly/slice_rational_fps.hpp"

using mint = modint998;

vc<mint> gen(int n) {
  vc<mint> f(n);
  FOR(i, n) f[i] = RNG(0, 100);
  return f;
}

void test() {
  using poly = vc<mint>;
  FOR(n, 1, 10) FOR(m, n) {
    poly P = gen(m), Q = gen(n);
    Q[0] = mint(1);
    poly f = P, g = Q;
    f.resize(100), g.resize(100);
    vc<mint> F = fps_div(f, g);
    FOR(i, 50) {
      poly A = slice_rational_fps(P, Q, i);
      poly B = {F.begin() + i, F.begin() + i + n - 1};
      assert(A == B);
    }
  }
  int n = 500;
  int m = 499;
  poly P = gen(m), Q = gen(n);
  Q[0] = mint(1);
  poly f = P, g = Q;
  f.resize(1000), g.resize(1000);
  vc<mint> F = fps_div(f, g);
  FOR(i, 500) {
    auto A = slice_rational_fps(P, Q, i);
    poly B = {F.begin() + i, F.begin() + i + n - 1};
    assert(A == B);
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