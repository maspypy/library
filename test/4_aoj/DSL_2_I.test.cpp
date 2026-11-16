#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/sum_assign.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void solve() {
  LL(N, Q);
  using AM = ActedMonoid_Sum_Assign<ll>;
  Lazy_SegTree<AM> seg(N);
  FOR(Q) {
    LL(t, L, R);
    ++R;
    if (t == 0) {
      LL(x);
      seg.apply(L, R, x);
    } else {
      print(seg.prod(L, R));
    }
  }
}

signed main() {
  solve();
  return 0;
}
