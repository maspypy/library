#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwick.hpp"
#include "ds/rectangle_sum.hpp"

void solve() {
  LL(N, Q);
  Point_Add_Rectangle_Sum<Group_Add<ll>> RS;
  FOR(_, N) {
    LL(x, y, w);
    RS.add_query(x, y, w);
  }
  FOR(_, Q) {
    LL(l, d, r, u);
    RS.sum_query(l, d, r, u);
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
