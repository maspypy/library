#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "nt/four_square.hpp"

void test() {
  FOR(N, 1000000) {
    auto [a, b, c, d] = four_square(N);
    assert(N == a * a + b * b + c * c + d * d);
  }
  vi TEN = {1};
  FOR(18) TEN.eb(TEN.back() * 10);
  FOR(100000) {
    ll K = RNG(0, 18);
    ll N = RNG(TEN[K], TEN[K + 1]);
    auto [a, b, c, d] = four_square(N);
    assert(N == a * a + b * b + c * c + d * d);
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