#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/parallel_binary_search.hpp"
#include "ds/fenwick/fenwick.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  using QT = tuple<ll, ll, ll>;
  VEC(QT, query, Q);

  auto I = argsort(A);
  FenwickTree<Monoid_Add<int>> bit(N);
  auto init = [&]() -> void { bit.reset(N); };
  auto upd = [&](int t) -> void { bit.add(I[t], 1); };
  auto check = [&](int q) -> bool {
    auto [l, r, k] = query[q];
    int x = bit.sum(l, r);
    return x > k;
  };
  auto OK = parallel_binary_search(Q, N, 0, init, upd, check);
  FOR(q, Q) {
    int t = OK[q];
    print(A[I[t - 1]]);
  }
}

signed main() {
  solve();

  return 0;
}
