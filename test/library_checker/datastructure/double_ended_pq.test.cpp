#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/dynamic_segtree.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  // 動的セグ木での二分探索
  LL(N, Q);
  VEC(int, A, N);
  const int LIM = 1'000'000'000;

  Dynamic_SegTree<Monoid_Add<int>, 30'000'000> seg(-LIM, LIM + 1);
  for (auto&& a: A) seg.multiply(a, 1);

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(x);
      seg.multiply(x, 1);
    }
    if (t == 1) {
      auto check = [&](auto e) -> bool { return e == 0; };
      int ANS = seg.max_right(check, -LIM);
      print(ANS);
      seg.multiply(ANS, -1);
    }
    if (t == 2) {
      auto check = [&](auto e) -> bool { return e == 0; };
      int ANS = seg.min_left(check, LIM + 1) - 1;
      print(ANS);
      seg.multiply(ANS, -1);
    }
  }
}

signed main() {
  solve();

  return 0;
}
