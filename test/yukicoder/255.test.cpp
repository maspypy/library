#define PROBLEM "https://yukicoder.me/problems/no/255"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/lazysegtree.hpp"
#include "alg/acted_monoid/cntsum_affine.hpp"

void solve() {
  LL(N, Q);
  using T = tuple<ll, ll, ll>;
  VEC(T, query, Q);
  for (auto&& [x, l, r]: query) ++r;

  vi X;
  for (auto&& [x, l, r]: query) X.eb(l), X.eb(r);
  UNIQUE(X);
  N = len(X);

  using AM = ActedMonoid_CntSum_Affine<ll>;
  vc<LazySegTree<AM>> seg;
  FOR(i, 5) seg.eb(LazySegTree<AM>(N));
  FOR(i, 5) FOR(j, N - 1) { seg[i].set(j, {X[j + 1] - X[j], 0}); }
  vc<i128> ANS(5);

  FOR(q, Q) {
    auto [x, l, r] = query[q];
    l = LB(X, l);
    r = LB(X, r);

    if (x >= 1) {
      --x;
      FOR(i, 5) {
        if (i != x) seg[i].apply(l, r, {0, 0});
        if (i == x) seg[i].apply(l, r, {1, 1});
      }
    } else {
      vi cnt(5);
      FOR(i, 5) { cnt[i] = seg[i].prod(l, r).se; }
      ll mx = 0;
      FOR(i, 5) chmax(mx, cnt[i]);
      ll s = 0;
      FOR(i, 5) if (cnt[i] == mx) s |= 1 << i;
      if (popcnt(s) > 1) continue;
      FOR(i, 5) if (cnt[i] == mx) ANS[i] += mx;
    }
  }
  ll mod = 1'000'000'000'000'000'009;
  FOR(i, 5) ANS[i] += seg[i].prod(0, N).se;
  FOR(i, 5) ANS[i] %= mod;
  print(ANS);
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
