#define PROBLEM "https://yukicoder.me/problems/no/1634"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

void solve() {
  INT(N, mod);
  vi F(20, 1);
  FOR(i, 19) F[i + 1] = F[i] * (i + 1);

  vi A;
  ll cf = 1;
  FOR(i, 1, 10) {
    LL(x);
    FOR(x) A.eb(i);
    cf *= F[x];
  }

  N = len(A);
  vi POW(N + 1, 1);
  FOR(i, N) POW[i + 1] = POW[i] * 10 % mod;

  using P = pair<int, int>;

  // とる集合, mod
  auto calc = [&](ll L, ll R, bool bl) -> vvc<int> {
    vc<P> dp;
    dp.eb(0, 0);
    FOR(i, L, R) {
      ll n = len(dp);
      vc<P> newdp;
      newdp.reserve(n * (N - (i - L)));
      FOR(j, n) {
        auto [s, x] = dp[j];
        FOR(k, N) {
          ll t = s | 1 << k;
          if (s == t) continue;
          int y = (x + A[i] * POW[k]) % mod;
          newdp.eb(t, y);
        }
      }
      swap(dp, newdp);
    }
    vvc<int> res(1 << N);
    int full = (1 << N) - 1;
    for (auto&& [s, x]: dp) {
      if (bl) {
        s = full - s;
        if (x) x = mod - x;
      }
      res[s].eb(x);
    }
    return res;
  };

  auto X = calc(0, N / 2, 0);
  auto Y = calc(N / 2, N, 1);

  ll ANS = 0;
  HashMap<int, 14> MP;
  FOR(s, 1 << N) {
    if (X[s].empty() || Y[s].empty()) continue;
    MP.reset();
    auto &P = X[s], &Q = Y[s];
    for (auto&& x: P) MP[x]++;
    for (auto&& x: Q)
      if (MP.count(x)) ANS += MP[x];
  }
  ANS /= cf;
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
