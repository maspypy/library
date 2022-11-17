#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/fps_exp.hpp"
#include "poly/online/online_exp.hpp"

using mint = modint998;

void test() {
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n + 1);
    FOR(i, n + 1) f[i] = RNG(mint::get_mod());
    return f;
  };
  FOR(n, 1000) {
    vc<mint> f = gen(n);
    f[0] = mint(0);
    vc<mint> g = fps_exp<mint>(f);
    Online_Exp<mint> X;
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
