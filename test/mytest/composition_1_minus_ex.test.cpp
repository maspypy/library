#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "poly/composition_f_1_minus_ex.hpp"
#include "poly/fps_composition.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n + 1);
    FOR(i, n + 1) f[i] = RNG(mint::get_mod());
    return f;
  };
  FOR(n, 100) {
    vc<mint> f = gen(n);
    vc<mint> g(n + 1);
    FOR(i, 1, n + 1) g[i] = -fact_inv<mint>(i);
    vc<mint> F = composition_1_minus_ex(f);
    vc<mint> G = fps_composition(f, g);
    assert(F == G);
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