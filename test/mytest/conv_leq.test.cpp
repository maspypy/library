#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution_leq.hpp"
#include "other/random.hpp"

RandomNumberGenerator RNG;

using mint = modint998;

vc<mint> gen(int n) {
  vc<mint> f(n);
  FOR(i, n) f[i] = RNG(0, mint::get_mod());
  return f;
}

void test_0() {
  FOR(100) {
    ll n = RNG(1, 10);
    ll m = RNG(1, 10);
    auto f = gen(n), g = gen(m);
    vc<mint> h(len(f) + len(g) - 1);
    FOR(i, len(f)) FOR(j, len(g)) if (i <= j) h[i + j] += f[i] * g[j];
    assert(convolution_leq(f, g, 0) == h);
  }
}

void test_1() {
  FOR(100) {
    ll n = RNG(1, 10);
    ll m = RNG(1, 10);
    auto f = gen(n), g = gen(m);
    vc<mint> h(len(f) + len(g) - 1);
    FOR(i, len(f)) FOR(j, len(g)) if (i < j) h[i + j] += f[i] * g[j];
    assert(convolution_leq(f, g, 1) == h);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}
