#define PROBLEM "https://atcoder.jp/contests/abc241/tasks/abc241_Ex"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/partial_frac_decomposition_1.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  vc<mint> A(N);
  vi B(N);
  FOR(i, N) read(A[i]), read(B[i]);

  // 分子
  vc<pair<ll, mint>> dp(1 << N);
  dp[0] = {0, 1};
  FOR(i, N) {
    mint a = A[i];
    a = a.pow(B[i] + 1);
    a = -a;
    FOR(s, 1 << i) { dp[s | 1 << i] = {dp[s].fi + B[i] + 1, dp[s].se * a}; }
  }

  // 分子が 1 の場合の部分分数分解
  vc<mint> f(N);
  f[0] = 1;
  f = partial_frac_decomposition_1<mint>(f, A);

  mint ANS = 0;
  auto calc = [&](ll p) -> mint {
    if (p < 0) return 0;
    mint ANS = 0;
    FOR(i, N) ANS += A[i].pow(p) * f[i];
    return ANS;
  };
  for (auto&& [p, cf]: dp) { ANS += calc(M - p) * cf; }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
