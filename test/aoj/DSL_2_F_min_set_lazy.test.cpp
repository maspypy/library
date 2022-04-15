#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/lazysegtree.hpp"
#include "alg/lazy_min_set.hpp"

void solve() {
  LL(N, Q);
  const ll MAX = (1LL << 31) - 1;
  using Lazy = Lazy_Min_Set<ll, MAX, -1>;
  LazySegTree<Lazy> seg(N);
  FOR(_, Q) {
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
