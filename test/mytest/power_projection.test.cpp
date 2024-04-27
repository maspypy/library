#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "poly/power_projection.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void test() {
  FOR(100) {
    FOR(N, 10) FOR(K, 10) {
      vc<mint> f(K + 1);
      vc<mint> wt(K + 1);
      FOR(k, K + 1) f[k] = RNG(0, 5), wt[k] = RNG(0, 5);
      vc<mint> A(N + 1);
      FOR(n, N + 1) {
        vc<mint> h = fps_pow<mint>(f, n);
        FOR(i, K + 1) A[n] += wt[i] * h[i];
      }
      vc<mint> B = power_projection<mint>(wt, f, N);
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