#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/fps_pow.hpp"
#include "poly/online/online_pow.hpp"

using mint = modint998;

void test() {
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n + 1);
    FOR(i, n + 1) f[i] = RNG(mint::get_mod());
    return f;
  };
  FOR(n, 1000) {
    vc<mint> f = gen(n);
    f[0] = mint(1);
    mint K = RNG(mint::get_mod());
    vc<mint> g = fps_pow_1<mint>(f, K);
    Online_Pow<mint> X(K);
    FOR(i, n + 1) { assert(g[i] == X.query(i, f[i])); }
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
