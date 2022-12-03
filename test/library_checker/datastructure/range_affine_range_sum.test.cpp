#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/sum_affine.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "mod/modint.hpp"

using mint = modint998;
using AM = ActedMonoid_Sum_Affine<mint>;

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  Lazy_SegTree<AM> seg(A);

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(l, r, a, b);
      seg.apply(l, r, {a, b});
    }
    elif (t == 1) {
      LL(l, r);
      print(seg.prod(l, r));
    }
  }
}

signed main() {
  solve();

  return 0;
}
