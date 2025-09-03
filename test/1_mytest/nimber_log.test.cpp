#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "nt/nimber/nimber_log.hpp"

void test_16() {
  FOR(n, 1, 65536) {
    Nimber16 x(n);
    u64 m = nimber_log(x);
    assert(root_16.pow(m) == x);
  }
}

void test_32() {
  FOR(1 << 15) {
    Nimber32 x(RNG_64());
    if (x == 0) continue;
    u64 n = nimber_log(x);
    assert(root_32.pow(n) == x);
  }
}

void test_64() {
  FOR(1 << 15) {
    Nimber64 x(RNG_64());
    if (x == 0) continue;
    u64 n = nimber_log(x);
    assert(root_64.pow(n) == x);
  }
  FOR(1 << 15) {
    Nimber64 x(RNG_64());
    Nimber64 y(RNG_64());
    if (x == 0 || y == 0) continue;
    u64 n = nimber_log(x, y);
    if (n != u64(-1)) assert(x.pow(n) == y);
  }
  FOR(1 << 15) {
    Nimber64 x(RNG_64());
    u64 n = RNG_64();
    Nimber64 y = x.pow(n);
    u64 m = nimber_log(x, y);
    assert(m != u64(-1) && x.pow(m) == y);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_16();
  test_32();
  test_64();
  solve();
  return 0;
}
