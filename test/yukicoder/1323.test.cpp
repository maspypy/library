#define PROBLEM "https://yukicoder.me/problems/no/1323"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/grid_bfs.hpp"

void solve() {
  LL(H, W, sx, sy, gx, gy);
  VEC(string, G, H);
  --sx, --sy, --gx, --gy;
  ll dx[] = {1, 0, -1, 0};
  ll dy[] = {0, 1, 0, -1};
  auto ng = [&]() -> void { print(-1); };

  auto dist_1 = grid_bfs<string>(G, sx, sy, "#", 4);
  auto dist_2 = grid_bfs<string>(G, gx, gy, "#", 4);

  ll D = dist_1[gx][gy];
  if (D == infty<int>) return ng();

  auto in_path = [&](int x, int y) -> bool {
    ll d1 = dist_1[x][y], d2 = dist_2[x][y];
    return d1 < infty<int> && d2 < infty<int> && d1 + d2 == D;
  };

  // unique path?
  int cnt = 0;
  FOR(x, H) FOR(y, W) if (in_path(x, y))++ cnt;
  if (cnt > D + 1) return print(D + D);

  ll ANS = infty<int>;

  // deg >= 3 の点を利用する場合
  FOR(x, H) FOR(y, W) if (G[x][y] != '#') {
    int deg = 0;
    FOR(d, 4) if (G[x + dx[d]][y + dy[d]] != '#') deg++;
    if (deg >= 3) {
      bool mid = in_path(x, y);
      if (x == sx && y == sy) mid = 0;
      if (x == gx && y == gy) mid = 0;
      if (mid) { chmin(ANS, 2 * D + 2); }
      elif (dist_1[x][y] < infty<int>) {
        chmin(ANS, 2 * (dist_1[x][y] + dist_2[x][y]) + 4);
      }
    }
  }

  // two edge disjoint path
  FOR(x, H) FOR(y, W) {
    if (in_path(x, y)) G[x][y] = '#';
  }
  G[sx][sy] = G[gx][gy] = '.';

  vv(int, dist, H, W, infty<int>);
  deque<pi> que;
  dist[sx][sy] = 0;
  que.eb(sx, sy);
  while (len(que)) {
    auto [x, y] = POP(que);
    FOR(d, 4) {
      int nx = x + dx[d], ny = y + dy[d];
      if (G[nx][ny] == '#') continue;
      if (x == sx && y == sy && nx == gx && ny == gy) continue;
      if (chmin(dist[nx][ny], dist[x][y] + 1)) { que.eb(nx, ny); }
    }
  }
  chmin(ANS, D + dist[gx][gy]);

  if (ANS == infty<int>) return ng();
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
