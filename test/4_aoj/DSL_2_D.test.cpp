#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/assign.hpp"

void solve() {
  using Mono = Monoid_Assign<ll, (1LL << 31) - 1>;
  LL(N, Q);
  Dual_SegTree<Mono> seg(N);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(L, R, x);
      seg.apply(L, ++R, x);
    } else {
      LL(i);
      print(seg.get(i));
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
