#define PROBLEM "https://yukicoder.me/problems/no/1234"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/min_add.hpp"
#include "ds/segtree/lazysegtree.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  LazySegTree<ActedMonoid_Min_Add<ll>> seg(A);
  LL(Q);
  FOR(Q) {
    LL(t, l, r, x);
    --l;
    if (t == 1) { seg.apply(l, r, x); }
    if (t == 2) print(seg.prod(l, r));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
