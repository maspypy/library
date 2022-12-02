#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/segtree.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  using Mono = Monoid_Affine<mint>;
  using F = Mono::value_type;

  vc<F> seg_raw(N);
  FOR(i, N) {
    LL(a, b);
    seg_raw[i] = {a, b};
  }

  SegTree<Mono> seg(seg_raw);

  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(i, a, b);
      seg.set(i, F({a, b}));
    } else {
      LL(L, R, x);
      auto f = seg.prod(L, R);
      print(Mono::eval(f, x));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
