#define PROBLEM "https://yukicoder.me/problems/no/579"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "other/connected_dp.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint107;

void solve() {
  LL(N);
  auto [states, edges] = connected_dp_squares::polygon_dp_graph(3);
  const int S = len(states);
  int E = len(edges);
  vc<int> count_line(E);
  FOR(e, E) {
    auto& now = states[edges[e].fi];
    auto& nxt = states[edges[e].se];
    int n = 0;
    FOR(i, len(now)) {
      if ((now[i] == -1) != (nxt[i] == -1)) ++n;
    }
    FOR(i, len(nxt) + 1) {
      bool a = (i == 0 ? 0 : nxt[i - 1] != -1);
      bool b = (i == len(nxt) ? 0 : nxt[i] != -1);
      if (a != b) ++n;
    }
    count_line[e] = n;
  }
  const int LIM = 4 * S + 10;

  // 辺を選んだ、選んでいない
  vv(mint, dp, 2, S);
  vc<mint> f(LIM);
  dp[0][0] = 1;
  FOR(i, LIM) {
    vv(mint, newdp, 2, S);
    FOR(e, E) {
      auto [a, b] = edges[e];
      newdp[0][b] += dp[0][a];
      newdp[1][b] += dp[1][a];
      newdp[1][b] += dp[0][a] * mint(count_line[e]);
    }
    swap(dp, newdp);
    f[i] = dp[1][1];
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
