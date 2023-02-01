#pragma once

// walls = "#" や、walls = {-1} など。
template <typename STRING>
vc<vc<int>> grid_bfs(vc<STRING>& G, int sx, int sy, STRING walls, int dmax) {
  assert(dmax == 4 || dmax == 8);
  int H = len(G);
  int W = len(G[0]);
  auto isin = [&](int x, int y) -> bool {
    if (x < 0 || H <= x) return false;
    if (y < 0 || W <= y) return false;
    return count(all(walls), G[x][y]) == 0;
  };
  int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
  int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

  vv(int, dist, H, W, infty<int>);
  deque<pair<int, int>> que;
  auto add = [&](int x, int y, int d) -> void {
    if (!isin(x, y)) return;
    if (chmin(dist[x][y], d)) que.eb(x, y);
  };
  add(sx, sy, 0);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop_front();
    FOR(d, dmax) {
      int nx = x + dx[d], ny = y + dy[d];
      add(nx, ny, dist[x][y] + 1);
    }
  }
  return dist;
}
