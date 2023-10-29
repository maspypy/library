#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

template <typename T>
void test() {
  vc<T> X;
  T mi = numeric_limits<T>::min();
  T ma = numeric_limits<T>::max();
  for (int x = -100; x <= 100; ++x) X.eb(T(x));
  for (int x = 0; x <= 100; ++x) X.eb(mi + T(x));
  for (int x = 0; x <= 100; ++x) X.eb(ma - T(x));
  for (auto& x: X) {
    for (auto& y: X) {
      if (y <= 0) continue;
      T k = floor(x, y);
      assert(0 <= x - k * y && x - k * y < y);
      k = ceil(x, y);
      assert(0 <= k * y - x && k * y - x < y);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test<int>();
  test<u32>();
  test<ll>();
  test<u64>();
  solve();
  return 0;
}