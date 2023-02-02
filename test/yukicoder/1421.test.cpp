#define PROBLEM "https://yukicoder.me/problems/no/1421"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/bitset/solve_linear.hpp"

using BS = bitset<50>;
const int K = 30;

void solve() {
  LL(N, M);
  vc<BS> A(M);
  vv(bool, rhs, K, M);
  FOR(i, M) {
    INT(n);
    FOR(n) {
      INT(j);
      --j;
      A[i][j] = 1;
    }
    INT(Y);
    FOR(k, K) { rhs[k][i] = Y >> k & 1; }
  }

  vc<int> ANS(N);
  FOR(k, K) {
    auto b = rhs[k];
    auto x = solve_linear<BS, bool>(M, N, A, b);
    if (x.empty()) return print(-1);
    FOR(i, N) if (x[0][i]) ANS[i] |= 1 << k;
  }
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}