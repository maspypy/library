#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dynamic_lazy_segtree.hpp"
#include "alg/acted_monoid/sum_affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  VEC(mint, A, N);
  using AM = ActedMonoid_Sum_Affine<mint>;
  Dynamic_Lazy_SegTree<AM, true> seg(10000000, 0, N);
  using np = decltype(seg)::np;
  vc<np> root(Q + 1);
  root[0] = seg.new_node(A);

  FOR(q, 1, Q + 1) {
    INT(t);
    if (t == 0) {
      INT(k, L, R, b, c);
      ++k;
      root[q] = seg.apply(root[k], L, R, {mint(b), mint(c)});
    }
    if (t == 1) {
      INT(k, s, l, r);
      ++k, ++s;
      root[q] = seg.copy_interval(root[k], root[s], l, r, {mint(1), mint(0)});
    }
    if (t == 2) {
      INT(k, l, r);
      ++k;
      root[q] = root[k];
      mint ANS = seg.prod(root[q], l, r);
      print(ANS);
    }
  }
}

signed main() { solve(); }