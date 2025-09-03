#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "alg/acted_monoid/sum_affine.hpp"
#include "ds/segtree/lazy_segtree.hpp"

using mint = modint998;
using AM = ActedMonoid_Sum_Affine<mint>;

void solve() {
  LL(N, Q);
  Lazy_SegTree<AM> seg(N, [&](int i) -> mint {
    INT(a);
    return a;
  });
  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(L, R, b, c);
      seg.apply(L, R, {b, c});
    } else {
      INT(L, R);
      print(seg.prod(L, R));
    }
  }
}

signed main() {
  solve();
  return 0;
}