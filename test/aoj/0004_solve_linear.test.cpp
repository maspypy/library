#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004"
#include "my_template.hpp"
#include "other/io2.hpp"
#include "string/split.hpp"
#include "linalg/solve_linear.hpp"

using Re = double;

void solve() {
  Re a, b, c, d, e, f;
  while (cin >> a >> b >> c >> d >> e >> f) {
    vv(Re, A, 2, 2);
    A[0] = {a, b};
    A[1] = {d, e};
    vc<Re> b = {c, f};
    auto res = solve_linear(A, b);
    auto x = res[0];
    printf("%.3f %.3f\n", x[0], x[1]);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
