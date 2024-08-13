#define PROBLEM "https://yukicoder.me/problems/no/1397"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/connected_dp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(W, H, N);
  if (N % 2 != 0) return print(0);
  auto [states, edges] = connected_dp_squares::polygon_dp_graph(H);
  const int S = len(states);
  const int E = len(edges);
  vc<int> count_line(E);
  FOR(e, E) {
    auto& now = states[edges[e].fi];
    auto& nxt = states[edges[e].se];
    vc<bool> A(H + 1), B(H + 1);
    FOR(i, -1, H) {
      int j = i + 1;
      bool a1 = (i == -1 ? 0 : now[i] != -1);
      bool a2 = (j == H ? 0 : now[j] != -1);
      A[j] = a1 != a2;
      bool b1 = (i == -1 ? 0 : nxt[i] != -1);
      bool b2 = (j == H ? 0 : nxt[j] != -1);
      B[j] = b1 != b2;
    }
    int x = 0;
    FOR(i, H + 1) if (!A[i] && B[i])++ x;
    count_line[e] = x;
  }

  // print(S, E);
  // state, horizonal edges
  vv(mint, dp, S, N / 2 + 1);
  dp[0][0] = 1;
  FOR(W + 1) {
    vv(mint, newdp, S, N / 2 + 1);
    FOR(e, E) {
      auto [a, b] = edges[e];
      int k = count_line[e];
      FOR(n, N / 2 - k + 1) newdp[b][n + k] += dp[a][n];
    }
    swap(dp, newdp);
  }
  print(dp[1][N / 2]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
