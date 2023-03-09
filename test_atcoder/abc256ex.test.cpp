#define PROBLEM "https://atcoder.jp/contests/abc256/tasks/abc256_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/intervals.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/sum_assign.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Intervals_Fast<int> I(N, 0);
  FOR(i, N) I.set(i, i + 1, A[i]);
  Lazy_SegTree<ActedMonoid_Sum_Assign<ll, -1>> seg(A);
  FOR(Q) {
    INT(t, L, R);
    --L;
    if (t == 2) {
      LL(y);
      I.set(L, R, y);
      seg.apply(L, R, y);
    }
    if (t == 3) { print(seg.prod(L, R)); }
    if (t == 1) {
      INT(d);
      vc<tuple<int, int, int>> tmp;
      I.enumerate_range(
          L, R, [&](int l, int r, int x) -> void { tmp.eb(l, r, x / d); },
          true);
      for (auto&& [l, r, x]: tmp) {
        seg.apply(l, r, x);
        I.set(l, r, x);
      }
    }
  }
}

signed main() {
  solve();
  return 0;
}
