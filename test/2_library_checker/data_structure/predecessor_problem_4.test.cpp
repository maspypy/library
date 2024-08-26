#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_01.hpp"

void solve() {
  INT(N, Q);
  STR(T);

  FenwickTree_01 bit(N, [&](int i) -> int { return T[i] - '0'; });
  FOR(Q) {
    INT(t, k);
    if (t == 0) {
      if (bit.sum(k, k + 1) == 0) bit.add(k, 1);
    }
    if (t == 1) {
      if (bit.sum(k, k + 1)) bit.add(k, -1);
    }
    if (t == 2) {
      int ans = bit.sum(k, k + 1);
      print(ans);
    }
    if (t == 3) {
      int n = bit.sum(0, k);
      int ans = (n == bit.sum_all() ? -1 : bit.kth(n));
      print(ans);
    }
    if (t == 4) {
      int n = bit.sum(0, k + 1);
      int ans = (n == 0 ? -1 : bit.kth(n - 1));
      print(ans);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}