#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "pds/segtree.hpp"
#include "alg/group_add.hpp"

void solve() {
  LL(N, Q);
  PersistentSegTree<Group_Add<int>> seg(N);
  VEC(ll, A, N);
  auto I = argsort(A);
  vi times;
  times.eb(seg.time());
  FOR(k, N) { times.eb(seg.set(times.back(), I[k], 1)); }
  FOR_(Q) {
    LL(L, R, k);
    auto check = [&](ll t) -> bool { return seg.prod(t, L, R) <= k; };
    ll t = binary_search(check, 0, N);
    print(A[I[t]]);
  }
}

signed main() {
  solve();

  return 0;
}
