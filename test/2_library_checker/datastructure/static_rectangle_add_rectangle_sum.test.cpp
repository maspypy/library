#define PROBLEM \
  "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/rectangle_add_rectangle_sum.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/add.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  Rectangle_Add_Rectangle_Sum<mint, int> X;

  FOR(N) {
    LL(l, d, r, u, w);
    X.add_query(l, r, d, u, w);
  }
  FOR(Q) {
    LL(l, d, r, u);
    X.sum_query(l, r, d, u);
  }
  print(X.calc());
}

signed main() {
  solve();
  return 0;
}
