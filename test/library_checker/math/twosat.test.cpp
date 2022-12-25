#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/twosat.hpp"

void solve() {
  STR(p, cnf);
  LL(N, M);
  TwoSat ts(N);
  FOR(i, M) {
    LL(a, b, c);
    a = (a > 0 ? a - 1 : a);
    b = (b > 0 ? b - 1 : b);
    ts.add(a, b);
  }
  auto [ok, A] = ts.calc();
  if (ok) {
    print("s SATISFIABLE");
    vc<int> ANS(N);
    FOR(i, N) ANS[i] = (A[i] ? i + 1 : -(i + 1));
    print("v", ANS, "0");
  } else {
    print("s UNSATISFIABLE");
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // LL(T);
  ll T = 1;
  FOR(_, T) solve();

  return 0;
}
