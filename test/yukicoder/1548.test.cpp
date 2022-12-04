#define PROBLEM "https://yukicoder.me/problems/no/1548"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/powersums_assign.hpp"

using mint = modint998;

void solve() {
  LL(N);
  using Mono = Monoid_Add_Array<mint, 5>;
  using ARR = typename Mono::value_type;
  VEC(mint, A, N);
  vc<ARR> seg_raw(N);
  FOR(i, N) {
    mint a = A[i];
    seg_raw[i] = {1, a, a * a, a * a * a, a * a * a * a};
  }
  Lazy_SegTree<ActedMonoid_Power_Sums_Assign<mint, 5>> seg(seg_raw);
  LL(Q);
  FOR(Q) {
    LL(t, u, v, w);
    if (u > v) swap(u, v);
    if (w < u || v < w) swap(u, v);
    --u, --v;
    if (t == 0) {
      LL(b);
      if (u < v) {
        seg.apply(u, v + 1, b);
      } else {
        seg.apply(0, v + 1, b);
        seg.apply(u, N, b);
      }
    } else {
      ARR e;
      if (u < v) {
        e = seg.prod(u, v + 1);
      } else {
        e = Mono::op(seg.prod(0, v + 1), seg.prod(u, N));
      }
      // print(e);
      mint n = e[0];
      mint mu = -e[1] / n;
      ll k = t;
      // sum (x+mu)^k
      mint ans = 0;
      FOR(i, k + 1) { ans += e[i] * mu.pow(k - i) * C<mint>(k, i); }
      ans /= n;
      print(ans);
    }
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
