#define PROBLEM \
  "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, a, r);
  VEC(mint, f, N);
  vc<mint> X(M);
  X[0] = a;
  FOR(i, M - 1) X[i + 1] = X[i] * r;

  auto Y = multipoint_eval(f, X);
  print(Y);
}

signed main() {
  solve();
  return 0;
}