#define PROBLEM \
  "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/query/rectangle_add_rectangle_sum.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/add.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  Rectangle_Add_Rectangle_Sum<Monoid_Add<mint>, int, false> X;

  FOR(N) {
    LL(l, d, r, u, w);
    X.add_query(l, r, d, u, w);
  }
  FOR(Q) {
    LL(l, d, r, u);
    X.sum_query(l, r, d, u);
  }
  auto ans = X.calc();
  for (auto&& x: ans) print(x);
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
