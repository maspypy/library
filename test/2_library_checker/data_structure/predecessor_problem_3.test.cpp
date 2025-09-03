#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/segtree.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  INT(N, Q);
  STR(T);

  SegTree<Monoid_Add<int>> seg(N, [&](int i) -> int { return T[i] - '0'; });

  FOR(Q) {
    INT(t, k);
    if (t == 0) {
      if (seg.prod(k, k + 1) == 0) seg.set(k, 1);
    }
    if (t == 1) {
      if (seg.prod(k, k + 1)) seg.set(k, 0);
    }
    if (t == 2) { print(seg.get(k)); }
    if (t == 3) {
      int ans = seg.max_right([&](auto e) -> bool { return e == 0; }, k);
      if (ans == N) ans = -1;
      print(ans);
    }
    if (t == 4) {
      int ans = seg.min_left([&](auto e) -> bool { return e == 0; }, k + 1) - 1;
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
