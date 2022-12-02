#define PROBLEM \
  "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/sortable_segtree.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  // クエリ先読みなしの方

  using AFF = Monoid_Affine<mint>;
  LL(N, Q);
  vc<int> key(N);
  vc<pair<mint, mint>> seg_raw(N);
  FOR(i, N) { read(key[i]), read(seg_raw[i]); }

  Sortable_SegTree<AFF> seg(1LL << 30, key, seg_raw);

  int i, p, l, r;
  pair<mint, mint> f;
  mint x;

  FOR(Q) {
    LL(t);
    if (t == 0) {
      read(i), read(p), read(f);
      seg.set(i, p, f);
    }
    if (t == 1) {
      read(l), read(r), read(x);
      auto f = seg.prod(l, r);
      print(AFF::eval(f, x));
    }
    if (t == 2) {
      read(l), read(r);
      seg.sort_inc(l, r);
    }
    if (t == 3) {
      read(l), read(r);
      seg.sort_dec(l, r);
    }
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