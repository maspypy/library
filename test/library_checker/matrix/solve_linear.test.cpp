#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/solve_linear.hpp"

using mint = modint998;
void solve() {
  LL(N, M);
  VV(mint, A, N, M);
  VEC(mint, b, N);
  auto xs = solve_linear(A, b);
  if (len(xs) == 0) return print(-1);
  print(len(xs) - 1);
  FOR(r, len(xs)) print(xs[r]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
