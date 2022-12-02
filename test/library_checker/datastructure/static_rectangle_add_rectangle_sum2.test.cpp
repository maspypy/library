#define PROBLEM \
  "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/coeffient_query_2d.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  Coefficient_Query_2D<2, 2, mint> X;
  FOR(N) {
    LL(x1, y1, x2, y2, w);
    X.add(x1, y1, +w);
    X.add(x1, y2, -w);
    X.add(x2, y1, -w);
    X.add(x2, y2, +w);
  }
  FOR(Q) {
    LL(x1, y1, x2, y2);
    --x1, --y1, --x2, --y2;
    X.query(x1, y1);
    X.query(x1, y2);
    X.query(x2, y1);
    X.query(x2, y2);
  }
  auto res = X.calc();
  FOR(q, Q) {
    mint ANS = 0;
    ANS += res[4 * q + 0];
    ANS -= res[4 * q + 1];
    ANS -= res[4 * q + 2];
    ANS += res[4 * q + 3];
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
