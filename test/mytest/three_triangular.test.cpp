#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "nt/three_triangular.hpp"

void test() {
  auto T = [&](ll x) -> ll { return x * (x - 1) / 2; };
  FOR(N, 1, 1000000) {
    auto [a, b, c] = three_triangular(N);
    assert(N == T(a) + T(b) + T(c));
  }
  vi TEN = {1};
  FOR(18) TEN.eb(TEN.back() * 10);
  FOR(100000) {
    ll K = RNG(0, 18);
    ll N = RNG(TEN[K], TEN[K + 1]);
    auto [a, b, c] = three_triangular(N);
    assert(N == T(a) + T(b) + T(c));
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