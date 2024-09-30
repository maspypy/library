#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "nt/nimber.hpp"

template <typename U>
void test() {
  using F = Nimber<U>;
  auto test = [&](F x) -> void {
    assert(x * x == x.square());
    assert(x.sqrt().square() == x);
    if (x != F(0)) assert(x * x.inverse() == F(1));
  };
  FOR(i, 1 << 20) { test(i); }
  FOR(10000) { test(F(RNG_64())); }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<u16>();
  test<u32>();
  test<u64>();
  solve();
}