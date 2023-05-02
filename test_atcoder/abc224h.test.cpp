#define PROBLEM "https://atcoder.jp/contests/abc224/tasks/abc224_h"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/dual_mcf.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);
  VV(ll, C, N, M);
  auto left = [&](int i) -> int { return i; };
  auto right = [&](int i) -> int { return N + i; };
  int z = N + M;
  Dual_MCF X(N + M + 1);
  FOR(i, N) FOR(j, M) X.add_constraint(left(i), right(j), -C[i][j]);
  FOR(i, N) X.add_constraint(left(i), z, 0);
  FOR(j, M) X.add_constraint(z, right(j), 0);
  FOR(i, N) X.add_b(left(i), A[i]), X.add_b(z, -A[i]);
  FOR(i, M) X.add_b(right(i), -B[i]), X.add_b(z, B[i]);
  auto [val, P] = X.solve();
  print(val);
}

signed main() {
  solve();
  return 0;
}