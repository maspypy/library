#define PROBLEM "https://atcoder.jp/contests/agc060/tasks/agc060_c"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/powertable.hpp"
#include "nt/rational.hpp"
#include "mod/O1_inverse.hpp"

using mint = modint998;
// using mint = Rational<ll, true>;

void solve() {
  LL(N, A, B);
  auto POW = powertable_1<mint>(2, N);

  // 2^N - 1 順列が heap である確率
  vc<mint> P(N + 1);
  P[0] = 1;
  FOR(i, N) { P[i + 1] = P[i] * P[i] / (POW[i + 1] - 1); }

  vv(mint, dp, A, B);
  dp[0][0] = mint(1) / (POW[N] - 1);

  mint ANS = 0;
  // dp[a][b]: パスと隣接していない subtree も決めたところまで
  FOR(a, A) FOR(b, B) {
    mint p = dp[a][b] * O1_inverse<mint>((POW[N - 1 - a] + POW[N - 1 - b] - 2).val);
    if (a + 1 < A) { dp[a + 1][b] += p * P[N - 2 - a]; }
    if (b + 1 < B) { dp[a][b + 1] += p * P[N - 2 - b]; }
    if (a + 1 == A) { ANS += p * P[N - 2 - a] * P[N - 2 - a] * P[N - 1 - b]; }
  }

  ANS /= P[N];
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
