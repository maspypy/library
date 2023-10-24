#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/three_square.hpp"
#include "random/base.hpp"

void test() {
  FOR(N, 1, 1000000) {
    if (N % 4 == 0) continue;
    ll n = N;
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) continue;
    auto [a, b, c] = three_square(N);
    assert(N == a * a + b * b + c * c);
  }
  vi TEN = {1};
  FOR(18) TEN.eb(TEN.back() * 10);
  FOR(100000) {
    ll K = RNG(0, 18);
    ll N = RNG(TEN[K], TEN[K + 1]);
    ll n = N;
    while (n % 4 == 0) n /= 4;
    if (n % 8 == 7) continue;
    auto [a, b, c] = three_square(N);
    assert(a * a + b * b + c * c == N);
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