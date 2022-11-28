#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/dynamic_lazysegtree.hpp"
#include "alg/acted_monoid/cntsum_add.hpp"

void solve() {
  auto f = [&](ll L, ll R) -> pi { return {R - L, 0}; };
  Dynamic_LazySegTree<ActedMonoid_CntSum_Add<ll>, 2000000> seg(0, 1LL << 30, f);
  LL(Q);
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { seg.apply(a, a + 1, b); }
    if (t == 1) { ANS += seg.prod(a, b + 1).se; }
  }
  print(ANS);
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
