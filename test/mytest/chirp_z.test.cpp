#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/multipoint.hpp"

void test() {
  using mint = modint998;
  const int mod = mint::get_mod();
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n);
    FOR(i, n) f[i] = RNG(0, mod);
    return f;
  };
  auto naive = [&](vc<mint> f, mint a, mint r, int m) -> vc<mint> {
    vc<mint> g(m);
    FOR(j, m) {
      mint pow = 1;
      FOR(i, len(f)) g[j] += f[i] * pow, pow *= a;
      a *= r;
    }
    return g;
  };
  FOR(n, 1, 100) FOR(m, 1, 100) {
    vc<mint> f = gen(n);
    mint a = RNG(1, mod);
    mint r = RNG(1, mod);
    auto A = multipoint_eval_on_geom_seq(f, a, r, m);
    auto B = naive(f, a, r, m);
    assert(A == B);
  }
  FOR(n, 1, 100) FOR(m, 1, 100) {
    vc<mint> f = gen(n);
    mint a = 0;
    mint r = RNG(1, mod);
    auto A = multipoint_eval_on_geom_seq(f, a, r, m);
    auto B = naive(f, a, r, m);
    assert(A == B);
  }
}

void solve() {
  test();
  LL(a, b);
  print(a + b);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
