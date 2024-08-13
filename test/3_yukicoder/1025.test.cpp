#define PROBLEM "https://yukicoder.me/problems/no/1025"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/primitive_root.hpp"

using mint = modint107;

void solve() {
  LL(p, n, k, b);
  const int g = primitive_root(p);
  vc<int> EXP(p - 1);
  vc<int> LOG(p);
  {
    EXP[0] = 1;
    FOR(i, p - 2) EXP[i + 1] = EXP[i] * ll(g) % p;
    FOR(i, p - 1) LOG[EXP[i]] = i;
  }
  k = gcd(k, p - 1);
  vc<int> root(p);
  FOR(x, 1, p) {
    int e = LOG[x];
    e %= k;
    root[x] = EXP[e];
  }

  vc<int> S;
  FOR(i, 0, p - 1, k) S.eb(EXP[i]);
  vc<int> B;
  FOR(v, p) if (root[v] == v) B.eb(v);

  vc<mint> dp(p);
  dp[0] = mint(1);
  FOR(n) {
    LL(a);
    vc<mint> newdp = dp;
    for (auto&& s: S) {
      int t = s * a % p;
      for (auto&& x: B) {
        int to = x + t;
        if (to >= p) to -= p;
        newdp[root[to]] += dp[x] * mint(k);
      }
    }
    swap(dp, newdp);
  }
  mint ANS = dp[root[b]];
  if (b != 0) ANS /= mint(len(S));
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
