#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/min_assign.hpp"

void solve() {
  LL(N, Q);
  using AM = ActedMonoid_Min_Assign<ll, -1>;
  vi seg_raw(N, (1LL << 31) - 1);
  Lazy_SegTree<AM> seg(seg_raw);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(L, R, x);
      seg.apply(L, ++R, x);
    } else {
      LL(L, R);
      print(seg.prod(L, ++R));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
