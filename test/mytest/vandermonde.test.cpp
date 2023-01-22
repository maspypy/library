#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "mod/modint.hpp"
#include "linalg/implicit_matrix/vandermonde.hpp"

using mint = modint998;

#include "poly/convolution.hpp"

vc<mint> gen(int N) {
  int mod = mint::get_mod();
  vc<mint> f(N);
  FOR(i, N) f[i] = RNG(mod);
  return f;
}

vc<mint> vandermonde_naive(vc<mint> f, bool transpose) {
  int N = len(f);
  vc<mint> g(N);
  if (!transpose) { FOR(i, N) FOR(j, N) g[i] += mint(i).pow(j) * f[j]; }
  if (transpose) { FOR(i, N) FOR(j, N) g[i] += mint(j).pow(i) * f[j]; }
  return g;
}

void test() {
  FOR(t, 2) {
    FOR(N, 1, 100) {
      vc<mint> f = gen(N);
      vc<mint> g1 = vandermonde<mint>(f, t, 0);
      vc<mint> g2 = vandermonde_naive(f, t);
      assert(g1 == g2);
      if (t == 0) {
        vc<mint> h = vandermonde<mint>(g1, t, 1);
        assert(f == h);
      }
    }
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