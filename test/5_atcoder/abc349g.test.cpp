#define PROBLEM "https://atcoder.jp/contests/abc349/tasks/abc349_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/array_on_divisors.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  auto pf = factor(M);
  VEC(ll, A, N);
  Array_On_Divisors<int> div_cnt(pf);
  for (auto &x: A) {
    if (M % x == 0) div_cnt[x]++;
  }
  div_cnt.divisor_zeta();
  Array_On_Divisors<mint> dp(pf);
  div_cnt.enumerate([&](ll d, int cnt) -> void { dp[d] = mint(2).pow(cnt) - 1; });
  dp.divisor_mobius();
  print(dp[M]);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
