#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/fps_inv.hpp"
#include "poly/online/online_division.hpp"

using mint = modint998;

void test() {
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n + 1);
    FOR(i, n + 1) f[i] = RNG(mint::get_mod());
    return f;
  };
  FOR(n, 1000) {
    vc<mint> f = gen(n), g = gen(n);
    g[0] = mint(1);
    vc<mint> h = convolution(f, fps_inv(g));
    h.resize(n + 1);
    Online_Division<mint> X;
    FOR(i, n + 1) { assert(h[i] == X.query(i, f[i], g[i])); }
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
