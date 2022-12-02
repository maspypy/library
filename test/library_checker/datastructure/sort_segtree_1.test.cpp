#define PROBLEM \
  "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/sortable_segtree.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  // クエリ先読みする方

  using AFF = Monoid_Affine<mint>;
  LL(N, Q);
  vc<int> key(N);
  vc<pair<mint, mint>> seg_raw(N);
  FOR(i, N) { read(key[i]), read(seg_raw[i]); }

  vc<int> all_key = key;
  using QT = tuple<int, int, int, int, int>;
  vc<QT> query(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(i, p, a, b);
      query[q] = {t, i, p, a, b};
      all_key.eb(p);
    }
    if (t == 1) {
      LL(l, r, x);
      query[q] = {t, l, r, x, 0};
    }
    if (t == 2 || t == 3) {
      LL(l, r);
      query[q] = {t, l, r, 0, 0};
    }
  }

  UNIQUE(all_key);
  for (auto&& k: key) k = LB(all_key, k);

  Sortable_SegTree<AFF> seg(len(all_key), key, seg_raw);

  for (auto&& [t, a, b, c, d]: query) {
    if (t == 0) {
      b = LB(all_key, b);
      seg.set(a, b, {mint(c), mint(d)});
    }
    if (t == 1) {
      auto f = seg.prod(a, b);
      print(AFF::eval(f, c));
    }
    if (t == 2) { seg.sort_inc(a, b); }
    if (t == 3) { seg.sort_dec(a, b); }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  FOR(T) solve();
  return 0;
}