#define PROBLEM "https://atcoder.jp/contests/abc234/tasks/abc234_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/cartesian_tree.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(int, A, N);
  CartesianTree<int, 1> X1(A);
  CartesianTree<int, 0> X2(A);
  Lazy_SegTree<ActedMonoid_Sum_Add<mint>> seg(N + 1);
  seg.set(0, mint(1));

  FOR(i, N) {
    auto [L1, R1] = X1.range[i];
    mint x1 = seg.prod(L1, i + 1);
    seg.apply(i + 1, R1 + 1, -x1 * mint(A[i]));

    auto [L2, R2] = X2.range[i];
    mint x2 = seg.prod(L2, i + 1);
    seg.apply(i + 1, R2 + 1, x2 * mint(A[i]));
  }
  print(seg.get(N));
}

signed main() {
  solve();

  return 0;
}