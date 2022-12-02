#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dualsegtree.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  DualSegTree<Monoid_Affine<mint>> seg(N);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(l, r, b, c);
      seg.apply(l, r, {mint(b), mint(c)});
    }
    if (t == 1) {
      LL(idx);
      mint x = A[idx];
      auto [a, b] = seg.get(idx);
      print(a * x + b);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
