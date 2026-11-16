#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/assign.hpp"

void solve() {
  using Mono = Monoid_Assign<ll>;
  LL(N, Q);
  Dual_SegTree<Mono> seg(N);
  seg.apply(0, N, (1LL << 31) - 1);
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
  solve();

  return 0;
}
