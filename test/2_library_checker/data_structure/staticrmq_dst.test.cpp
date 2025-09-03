#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sparse_table/disjoint_sparse_table.hpp"
#include "alg/monoid/min.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);

  Disjoint_Sparse_Table<Monoid_Min<int>> seg(A);

  FOR(Q) {
    LL(a, b);
    print(seg.prod(a, b));
  }
}

signed main() {
  solve();
  return 0;
}