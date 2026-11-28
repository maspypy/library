#define PROBLEM \
  "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"

using mint = modint998;
using Mono = Monoid_Affine<mint>;

void solve() {
  LL(N, Q);
  Dynamic_SegTree_Sparse<Mono, false> seg(0, N);

  using np = decltype(seg)::np;

  np root = seg.new_root();

  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(p);
      mint c, d;
      read(c, d);
      SHOW(t, p, c, d);
      pair<mint, mint> f = {c, d};
      root = seg.set(root, p, f);
    } else {
      int l, r;
      mint x;
      read(l, r, x);
      SHOW(t, l, r, x);
      auto f = seg.prod(root, l, r);
      mint ANS = Mono::eval(f, x);
      print(ANS);
    }
  }
}

signed main() {
  solve();
  return 0;
}