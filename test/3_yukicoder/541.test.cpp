#define PROBLEM "https://yukicoder.me/problems/no/541"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/connected_dp.hpp"
#include "mod/modint.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint107;

void solve() {
  LL(N);
  auto [states, edges] = connected_dp_squares::polygon_dp_graph(3);
  const int S = len(states);
  vc<mint> dp(S);
  dp[0] = 1;
  int LIM = 2 * S + 10;
  vc<mint> f(LIM);
  FOR(i, LIM) {
    vc<mint> newdp(S);
    for (auto&& [a, b]: edges) { newdp[b] += dp[a]; }
    swap(dp, newdp);
    f[i] = dp[1];
  }

  mint ANS = interpolate_linear_rec<mint>(f, N, 0);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
