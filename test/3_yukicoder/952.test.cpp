#define PROBLEM "https://yukicoder.me/problems/no/952"

#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  A.insert(A.begin(), 0);

  auto Ac = cumsum<ll>(A);

  auto f = [&](ll L, ll R) -> ll {
    SHOW(L, R);
    ll x = Ac[R] - Ac[L + 1];
    return x * x;
  };

  vi dp(N + 2, infty<ll>);
  dp[0] = 0;
  vi ANS;
  FOR(N) {
    dp = monge_dp_update<ll>(N + 1, dp, f);
    SHOW(dp);
    ANS.eb(dp[N + 1]);
  }
  reverse(all(ANS));
  for (auto& x : ANS) print(x);
}

signed main() { solve(); }
