#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/hungarian.hpp"

void solve() {
  LL(N);
  VV(ll, A, N, N);
  auto [ans, match, X, Y] = hungarian(A);
  print(ans);
  print(match);

  assert(SUM(X) + SUM(Y) == ans);
  FOR(i, N) FOR(j, N) assert(X[i] + Y[j] <= A[i][j]);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}
