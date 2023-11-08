#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "nt/digit_sum.hpp"
#include "random/base.hpp"

int naive(u64 x) {
  int res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }
  return res;
}

void test() {
  FOR(x, 1000000) { assert(naive(x) == digit_sum(x)); }
  FOR(1000000) {
    u64 x = RNG_64();
    assert(naive(x) == digit_sum(x));
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
  return 0;
}
