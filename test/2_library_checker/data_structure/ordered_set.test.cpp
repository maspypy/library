#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_01.hpp"

void solve() {
  INT(N, Q);
  FenwickTree_01 bit(TEN[9] + 1);
  FOR(N) {
    INT(a);
    bit.add(a);
  }

  auto Q0 = [&]() -> void {
    INT(x);
    if (!bit.get(x)) bit.add(x);
  };
  auto Q1 = [&]() -> void {
    INT(x);
    if (bit.get(x)) bit.remove(x);
  };
  auto Q2 = [&]() -> void {
    INT(x);
    --x;
    int ans = (x < bit.sum_all() ? bit.kth(x) : -1);
    print(ans);
  };
  auto Q3 = [&]() -> void {
    INT(x);
    print(bit.sum(x + 1));
  };
  auto Q4 = [&]() -> void {
    INT(x);
    int ans = bit.prev(x);
    print(ans);
  };
  auto Q5 = [&]() -> void {
    INT(x);
    int ans = bit.next(x);
    if (ans == bit.N) ans = -1;
    print(ans);
  };

  FOR(Q) {
    INT(t);
    if (t == 0) Q0();
    if (t == 1) Q1();
    if (t == 2) Q2();
    if (t == 3) Q3();
    if (t == 4) Q4();
    if (t == 5) Q5();
  }
}

signed main() {
  solve();

  return 0;
}
