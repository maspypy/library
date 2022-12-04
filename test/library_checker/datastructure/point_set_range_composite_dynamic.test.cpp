#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  using Mono = Monoid_Affine<mint>;
  using X = Mono::value_type;
  LL(N, Q);
  VEC(X, dat, N);

  Dynamic_SegTree<Mono, false, 1000000> seg(N);
  auto root = seg.new_node(dat);

  FOR(Q) {
    LL(t, a, b, c);
    if (t == 0) { seg.set(root, a, {b, c}); }
    if (t == 1) { print(Mono::eval(seg.prod(root, a, b), c)); }
  }
}

signed main() {
  solve();

  return 0;
}
