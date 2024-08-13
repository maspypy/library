#define PROBLEM "https://atcoder.jp/contests/abc301/tasks/abc301_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/grid_bfs.hpp"

void solve() {
  LL(H, W, T);
  VEC(string, A, H);

  vc<pi> pos;
  FOR(x, H) FOR(y, W) if (A[x][y] == 'S') pos.eb(x, y);
  FOR(x, H) FOR(y, W) if (A[x][y] == 'o') pos.eb(x, y);
  FOR(x, H) FOR(y, W) if (A[x][y] == 'G') pos.eb(x, y);

  ll N = len(pos);

  vv(int, dist, N, N);
  FOR(i, N) {
    auto [sx, sy] = pos[i];
    auto mat = grid_bfs<string>(A, sx, sy, "#", 4);
    FOR(j, N) {
      auto [a, b] = pos[j];
      dist[i][j] = mat[a][b];
    }
  }

  vv(ll, dp, 1 << N, N, infty<ll>);
  dp[1][0] = 0;

  FOR(s, 1 << N) {
    FOR(a, N) {
      if (dp[s][a] == infty<ll>) continue;
      FOR(b, N) {
        ll t = s | 1 << b;
        if (s == t) continue;
        chmin(dp[t][b], dp[s][a] + dist[a][b]);
      }
    }
  }

  if (dist[0][N - 1] > T) return print(-1);

  ll ANS = 0;
  FOR(s, 1 << N) {
    if (dp[s][N - 1] > T) continue;
    ll n = popcnt(s) - 2;
    chmax(ANS, n);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
