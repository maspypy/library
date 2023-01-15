#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/four_square.hpp"
#include "random/base.hpp"

void test() {
  FOR(x, 1000) {
    auto [a, b, c, d] = four_square(x);
    assert(a * a + b * b + c * c + d * d == x);
  }
  FOR(1000) {
    ll x = RNG(0, 1'000'000'000);
    auto [a, b, c, d] = four_square(x);
    assert(a * a + b * b + c * c + d * d == x);
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
