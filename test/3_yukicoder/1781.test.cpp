#define PROBLEM "https://yukicoder.me/problems/no/1781"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/primesum.hpp"
#include "nt/multiplicative_sum.hpp"

using mint = modint998;

void solve() {
  // x lcm(A) = n <= M となる組 (x,A) の数え上げ
  // p^k の寄与を求める
  LL(N, M);
  ll LIM = 40;
  vc<mint> dp(LIM);
  FOR(e, LIM) {
    // a + max(b1,...,bN) = e となるものの数え上げ
    // max(b1,...,bN) <= e となるものの数え上げ
    dp[e] = mint(e + 1).pow(N);
  }

  PrimeSum<mint> X(M);
  X.calc_count();

  auto f_pe = [&](ll p, ll e) -> mint { return dp[e]; };
  auto f_psum = [&](ll x) -> mint { return X[x] * dp[1]; };

  mint ANS = multiplicative_sum<mint>(M, f_pe, f_psum);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
