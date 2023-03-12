#define PROBLEM "https://yukicoder.me/problems/no/1667"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/dynamic_modint.hpp"

using mint = dmint;

void solve() {
  LL(N, mod);
  mint::set_mod(mod);

  vc<mint> f(N + 1);
  FOR(n, 1, N + 1) f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2));

  // 点、辺
  vv(mint, DP, N + 1, N + 1);
  DP[0][0] = 1;
  FOR(n, 1, N + 1) {
    FOR(m, n + 1) {
      FOR(k, 1, n + 1) {
        mint cf = C<mint, false, true>(n - 1, k - 1);
        cf *= f[k];
        ll n1 = n - k;
        ll m1 = m - (k - 1);
        if (n1 < 0 || m1 < 0) continue;
        DP[n][m] += DP[n1][m1] * cf;
      }
    }
  }
  vc<mint> ANS = DP[N];
  ANS.pop_back();
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
