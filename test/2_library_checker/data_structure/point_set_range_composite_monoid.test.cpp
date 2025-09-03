#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"
#include "ds/segtree/segtree.hpp"

using mint = modint998;
using Mono = Monoid_Affine<mint>;

void solve() {
  LL(N, Q);
  SegTree<Mono> seg(N, [&](int i) -> pair<mint, mint> {
    INT(a, b);
    return {a, b};
  });
  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(i, a, b);
      seg.set(i, {a, b});
    } else {
      INT(L, R, x);
      print(Mono::eval(seg.prod(L, R), mint(x)));
    }
  }
}

signed main() {
  solve();
  return 0;
}