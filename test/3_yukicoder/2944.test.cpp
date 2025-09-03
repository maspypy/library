#define PROBLEM "https://yukicoder.me/problems/no/2944"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/famous/partition_number.hpp"
#include "mod/modint.hpp"

using mint = modint998;
void solve() {
  auto A = partition_number_2d<mint>(4000, 4000);
  ll N = 4000;
  FOR(i, N + 1) FOR(j, N) A[i][j + 1] += A[i][j];

  LL(Q);
  FOR(Q) {
    LL(t, n, k);
    print(A[n][k]);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
