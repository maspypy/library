#define PROBLEM "https://judge.yosupo.jp/problem/adjugate_matrix"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/adjugate_matrix.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VV(mint, A, N, N);
  A = adjugate_matrix(A);
  FOR(i, N) print(A[i]);
}

signed main() { solve(); }