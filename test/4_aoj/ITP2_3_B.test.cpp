#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/minmax.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  using Mono = Monoid_MinMax<int>;
  SegTree<Mono> seg(N, [&](int i) { return Mono::from_element(A[i]); });
  LL(Q);
  FOR(Q) {
    LL(t, b, e);
    if (t == 0) print(seg.prod(b, e).fi);
    if (t == 1) print(seg.prod(b, e).se);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
