#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "ds/segtree/dynamic_segtree.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  Dynamic_SegTree<Monoid_Add<int>, true, 5'000'000> seg(0, N);
  using np = decltype(seg)::np;
  auto I = argsort(A);

  vc<np> roots;
  roots.eb(seg.new_node(0, N));
  FOR(k, N) { roots.eb(seg.set(roots.back(), I[k], 1)); }
  FOR(Q) {
    LL(L, R, k);
    auto check = [&](ll t) -> bool { return seg.prod(roots[t], L, R) <= k; };
    ll t = binary_search(check, 0, N);
    print(A[I[t]]);
  }
}

signed main() {
  solve();

  return 0;
}
