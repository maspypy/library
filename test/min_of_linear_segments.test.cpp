#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/random.hpp"
#include "mod/min_of_linear_segments.hpp"

pair<vc<int>, vc<int>> naive(int a, int b, int mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  vc<int> A;
  int last_y = b;
  FOR(x, 1, mod + 1) {
    int y = (ll(a) * x + b) % mod;
    if (chmin(last_y, y)) A.eb(x);
  }
  vc<int> X = {0};
  vc<int> DX;
  int dx = -1;
  for (auto&& x: A) {
    if (X.back() + dx == x) {
      X.back() = x;
    } else {
      dx = x - X.back();
      DX.eb(dx);
      X.eb(x);
    }
  }
  return {X, DX};
}

void test() {
  RandomNumberGenerator RNG;
  FOR(mod, 1, 1000) {
    FOR(10) {
      int mod = RNG(1, 1000);
      int a = RNG(0, mod);
      int b = RNG(0, mod);
      auto [X1, DX1] = naive(a, b, mod);
      auto [X2, DX2] = min_of_linear_segments(a, b, mod);
      assert(X1 == X2);
      assert(DX1 == DX2);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
