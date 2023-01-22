#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "ds/offline_query/coeffient_query_2d.hpp"

void solve() {
  LL(N, Q);
  Coefficient_Query_2D<1, 1, ll, int> X;
  FOR(i, N) {
    LL(x, y, w);
    X.add_query(x, y, w);
  }
  FOR(Q) {
    LL(x1, y1, x2, y2);
    --x1, --y1, --x2, --y2;
    X.sum_query(x1, y1);
    X.sum_query(x1, y2);
    X.sum_query(x2, y1);
    X.sum_query(x2, y2);
  }
  auto res = X.calc(0);
  vi ANS(Q);
  FOR(q, Q)
  ANS[q] = res[4 * q] - res[4 * q + 1] - res[4 * q + 2] + res[4 * q + 3];
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}