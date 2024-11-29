#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"

void solve() {
  INT(N, Q);
  STR(T);

  FenwickTree<Monoid_Add<int>> bit(N, [&](int i) -> int { return T[i] - '0'; });
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
      int ans = bit.max_right([&](int x) -> bool { return x <= 0; }, k);
      if (ans == N) ans = -1;
      print(ans);
    }
    if (t == 4) {
      int ans = bit.min_left([&](int x) -> bool { return x <= 0; }, k + 1) - 1;
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