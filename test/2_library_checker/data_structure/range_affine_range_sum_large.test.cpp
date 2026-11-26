#define PROBLEM \
  "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "alg/acted_monoid/sum_affine.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"

using mint = modint998;
using AM = ActedMonoid_Sum_Affine<mint>;

void solve() {
  LL(N, Q);
  Dynamic_Lazy_SegTree<AM, false> seg(0, N);
  using np = decltype(seg)::np;

  np root = seg.new_root();

  FOR(Q) {
    INT(t, l, r);
    if (t == 0) {
      mint b, c;
      read(b, c);
      SHOW(t, l, r, b, c);
      pair<mint, mint> f = {b, c};
      root = seg.apply(root, l, r, f);
    } else {
      SHOW(t, l, r);
      print(seg.prod(root, l, r));
    }
  }
}

signed main() {
  solve();
  return 0;
}