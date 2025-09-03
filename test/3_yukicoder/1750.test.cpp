#define PROBLEM "https://yukicoder.me/problems/no/1750"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/matrix_pow.hpp"

using mint = modint998;

void solve() {
  LL(N, M, T);
  vv(mint, A, N, N);
  FOR(M) {
    LL(a, b);
    A[a][b] = 1;
    A[b][a] = 1;
  }
  A = matrix_pow(A, T);
  print(A[0][0]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}