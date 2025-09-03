#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  INT(N, Q);
  vc<mint> A(N);
  FOR(i, N) {
    u32 x;
    read(x);
    A[i] = mint::raw(x);
  }
  Dual_SegTree<Monoid_Affine<mint>> seg(N);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      u32 l, r, b, c;
      read(l, r, b, c);
      seg.apply(l, r, {mint::raw(b), mint::raw(c)});
    }
    if (t == 1) {
      u32 idx;
      read(idx);
      mint x = A[idx];
      auto [a, b] = seg.get(idx);
      print(a * x + b);
    }
  }
}

signed main() {
  solve();
  return 0;
}
