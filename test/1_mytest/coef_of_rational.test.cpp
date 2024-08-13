#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "poly/coef_of_rational_fps.hpp"
#include "random/base.hpp"

template <typename mint>
void test() {
  FOR(N, 20) {
    FOR(M, 20) {
      FOR(10) {
        vc<mint> f(N), g(M);
        FOR(i, N) f[i] = RNG(0, 3);
        FOR(i, M) g[i] = RNG(0, 3);
        vc<mint> F = f, G = g;
        F.resize(20);
        G.resize(20);
        if (G[0] == mint(0)) continue;
        F = fps_div(F, G);
        FOR(k, 20) {
          mint x = coef_of_rational_fps<mint>(f, g, k);
          assert(x == F[k]);
        }
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<modint998>();
  test<modint107>();
  solve();
}