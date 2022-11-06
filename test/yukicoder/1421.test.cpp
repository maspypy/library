#define PROBLEM "https://yukicoder.me/problems/no/1421"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/solve_linear_xor.hpp"

void solve() {
  LL(N, M);
  vv(int, mat, M, N);
  vc<int> rhs(M);

  FOR(i, M) {
    LL(n);
    VEC(int, B, n);
    for (auto&& x: B) --x;
    for (auto&& b: B) mat[i][b] = 1;

    LL(Y);
    rhs[i] = Y;
  }

  auto ANS = solve_linear_xor<int>(M, N, mat, rhs);
  if (ANS.empty()) return print(-1);
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
