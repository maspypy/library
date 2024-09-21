#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/frobenius.hpp"

using mint = modint998;

void solve() {
  LL(N, exp);
  VV(mint, A, N, N);
  Frobenius_Form<mint> FB(A);
  A = FB.pow(exp);
  FOR(i, N) print(A[i]);
}

signed main() {
  solve();
  return 0;
}