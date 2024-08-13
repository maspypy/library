#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/poly_divmod.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, f, N);
  VEC(mint, g, M);
  auto [q, r] = poly_divmod(f, g);
  print(len(q), len(r));
  print(q);
  print(r);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
