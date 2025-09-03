#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/sum_assign.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void solve() {
  LL(N, Q);
  using AM = ActedMonoid_Sum_Assign<ll, 12345>;
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
