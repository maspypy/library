#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/multipoint_evaluation_for_prefix_product.hpp"

using mint = modint998;

void test() {
  int N = RNG(0, 10);
  int M = RNG(0, 10);
  vvc<mint> poly(M);
  vc<mint> point(N);
  vc<int> CNT(N);
  FOR(i, M) {
    int d = RNG(0, 5);
    vc<mint> f(d + 1);
    FOR(k, d + 1) f[k] = RNG(0, 2);
    poly[i] = f;
  }
  FOR(i, N) point[i] = RNG(0, 10);
  FOR(i, N) CNT[i] = RNG(0, M + 1);

  vc<mint> god(N);
  FOR(i, N) {
    mint ans = 1;
    FOR(j, CNT[i]) {
      mint p = 1;
      mint y = 0;
      for (auto& x: poly[j]) { y += x * p, p *= point[i]; }
      ans *= y;
    }
    god[i] = ans;
  }
  vc<mint> Y = multipoint_evaluation_for_prefix_product<mint>(poly, point, CNT);
  assert(god == Y);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(100000) test();
  solve();
  return 0;
}
