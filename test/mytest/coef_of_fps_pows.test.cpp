#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "poly/coef_of_fps_pows.hpp"

using mint = modint998;

void test() {
  FOR(100) {
    FOR(N, 10) FOR(K, 10) {
      vc<mint> f(K + 1);
      FOR(k, K + 1) f[k] = RNG(0, 5);
      vc<mint> A(N + 1);
      FOR(n, N + 1) {
        vc<mint> g = fps_pow<mint>(f, n);
        A[n] = g[K];
      }
      vc<mint> B = coef_of_fps_pows<mint>(f, K, N);
      assert(A == B);
    }
  }
  FOR(100) {
    FOR(N, 10) FOR(K, 10) {
      vc<mint> f(K + 1);
      vc<mint> g(K + 1);
      FOR(k, K + 1) f[k] = RNG(0, 5), g[k] = RNG(0, 5);
      vc<mint> A(N + 1);
      FOR(n, N + 1) {
        vc<mint> h = convolution<mint>(fps_pow<mint>(f, n), g);
        A[n] = h[K];
      }
      vc<mint> B = coef_of_fps_pows<mint>(f, K, N, g);
      assert(A == B);
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
