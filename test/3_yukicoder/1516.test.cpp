#define PROBLEM "https://yukicoder.me/problems/no/1516"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  ll LIM = 300;
  vc<mint> A(LIM);
  vc<mint> B(LIM);
  using P = pair<mint, mint>;

  vv(P, dp, K, K);
  FOR(a, K) FOR(b, K) if (a != b) dp[a][b] = {mint(1), mint(a + b)};

  FOR(k, 2, LIM) {
    FOR(a, K) FOR(b, K) {
      A[k] += dp[a][b].fi;
      B[k] += dp[a][b].se;
    }
    vv(P, newdp, K, K);
    FOR(a, K) FOR(b, K) FOR(c, K) {
      if (a == b || a == c || b == c) continue;
      if (a < b && b < c) continue;
      if (a > b && b > c) continue;
      newdp[b][c].fi += dp[a][b].fi;
      newdp[b][c].se += dp[a][b].se + mint(c) * dp[a][b].fi;
    }
    swap(dp, newdp);
  }

  mint a = interpolate_linear_rec<mint>(A, N, 10);
  mint b = interpolate_linear_rec<mint>(B, N, 10);
  print(a, b);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
