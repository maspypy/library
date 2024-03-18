#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "poly/compositional_inverse.hpp"
#include "random/base.hpp"

using mint = modint998;

void test() {
  FOR(N, 100) {
    vc<mint> f(N);
    FOR(i, 1, N) f[i] = RNG(1, 10);
    vc<mint> A = compositional_inverse<mint>(f);
    vc<mint> B = compositional_inverse_old<mint>(f);
    assert(A == B);
    vc<mint> F = composition<mint>(f, A);
    vc<mint> G = composition<mint>(A, f);
    FOR(i, N) {
      if (i == 1) {
        assert(F[i] == mint(1));
        assert(G[i] == mint(1));
      } else {
        assert(F[i] == mint(0));
        assert(G[i] == mint(0));
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
  test();
  solve();
}
