#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_polynomials"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/poly_gcd.hpp"

using mint = modint998;
void solve() {
  LL(N, M);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto [d, x, y] = poly_ext_gcd(A, B);
  if (len(d) > 1) return print(-1);
  mint c = mint(1) / d[0];
  FOR(i, len(x)) x[i] *= c;
  print(len(x));
  if (len(x)) print(x);
}

signed main() {
  solve();
  return 0;
}
