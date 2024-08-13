#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "poly/composition_f_x_plus_1x.hpp"
#include "random/base.hpp"

using mint = modint998;

void test() {
  FOR(N, 0, 1000) {
    vc<mint> f(N + 1);
    FOR(i, N + 1) f[i] = RNG(0, mint::get_mod());
    vc<mint> F(2 * N + 1);
    FOR(i, N + 1) {
      FOR(j, i + 1) { F[N + j - (i - j)] += f[i] * C<mint>(i, j); }
    }
    vc<mint> G = composition_f_x_plus_1x<mint>(f);
    assert(F == G);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
};

signed main() {
  test();
  solve();
}
