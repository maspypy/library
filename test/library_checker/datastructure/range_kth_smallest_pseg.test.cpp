#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/group/add.hpp"
#include "ds/pds/segtree.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  Persistent_SegTree<Monoid_Add<int>, 5'000'000> seg(N);
  using np = decltype(seg)::Node *;
  auto I = argsort(A);

  vc<np> roots;
  roots.eb(seg.new_node(vc<int>(N)));
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
