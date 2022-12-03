#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "ds/offline_query/point_add_rectangle_sum.hpp"

void solve() {
  LL(N, Q);
  Point_Add_Rectangle_Sum<Monoid_Add<ll>, int> RS;
  FOR(N) {
    LL(x, y, w);
    RS.add_query(x, y, w);
  }
  FOR(Q) {
    LL(l, d, r, u);
    RS.sum_query(l, r, d, u);
  }
  auto ANS = RS.calc();
  for (auto&& x: ANS) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
