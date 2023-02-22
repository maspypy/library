// 始点を固定して、ハミルトンパスを作る。偶数ならサイクルにする。
// 高次元版：https://codeforces.com/contest/863/submission/194294053
vc<pair<int, int>> grid_hamiltonian_path(int H, int W, int sx = 0, int sy = 0) {
  using P = pair<int, int>;
  assert(H >= 2 && W >= 2); //とりあえず
  if (H % 2 == 0 && W % 2 == 1) {
    vc<P> path = grid_hamiltonian_path(W, H, sy, sx);
    for (auto&& x: path) swap(x.fi, x.se);
    return path;
  }
  if (W % 2 == 0) {
    vc<P> path;
    path.reserve(H * W);
    FOR(j, W) path.eb(0, j);
    FOR_R(j, W) {
      if (j % 2 == 1) FOR(i, 1, H) path.eb(i, j);
      if (j % 2 == 0) FOR_R(i, 1, H) path.eb(i, j);
    }
    int idx = -1;
    FOR(i, len(path)) if (path[i].fi == sx && path[i].se == sy) idx = i;
    rotate(path.begin(), path.begin() + idx, path.end());
    return path;
  }

  assert(H * W % 2 == 1);
  if ((sx + sy) % 2 == 1) return {};
  if (sx % 2 == 1) {
    vc<P> path;
    path.reserve(H * W);
    FOR_R(i, sx + 1) {
      if (i % 2 == 1) FOR_R(j, sy + 1) path.eb(i, j);
      if (i % 2 == 0) FOR(j, sy + 1) path.eb(i, j);
    }
    FOR(j, sy + 1, W) {
      if (j % 2 == 0) FOR(i, sx + 1) path.eb(i, j);
      if (j % 2 == 1) FOR_R(i, sx + 1) path.eb(i, j);
    }
    FOR_R(j, W) {
      if (j % 2 == 0) FOR(i, sx + 1, H) path.eb(i, j);
      if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i, j);
    }
    return path;
  }
  if (sx == H - 1) {
    vc<P> path = grid_hamiltonian_path(H, W, 0, sy);
    for (auto&& x: path) x.fi = H - 1 - x.fi;
    return path;
  }
  if (sy == W - 1) {
    vc<P> path = grid_hamiltonian_path(H, W, sx, 0);
    for (auto&& x: path) x.se = W - 1 - x.se;
    return path;
  }
  if (sx != 0 && sy == 0) {
    vc<P> path = grid_hamiltonian_path(W, H, sy, sx);
    for (auto&& x: path) swap(x.fi, x.se);
    return path;
  }
  vc<P> path;
  path.reserve(H * W);
  if (sx == 0) {
    FOR_R(j, sy + 1) {
      if (j % 2 == 0) FOR(i, H - 1) path.eb(i, j);
      if (j % 2 == 1) FOR_R(i, H - 1) path.eb(i, j);
    }
    FOR(j, W) path.eb(H - 1, j);
    FOR_R(j, sy + 1, W) {
      if (j % 2 == 0) FOR_R(i, H - 1) path.eb(i, j);
      if (j % 2 == 1) FOR(i, H - 1) path.eb(i, j);
    }
    return path;
  }
  assert(0 < sx && sx < H - 1 && 0 < sy && sy < W - 1);
  FOR_R(j, sy + 1) path.eb(sx, j);
  FOR(j, sy + 1) {
    if (j % 2 == 0) FOR_R(i, sx) path.eb(i, j);
    if (j % 2 == 1) FOR(i, sx) path.eb(i, j);
  }
  FOR(i, sx + 1) {
    if (i % 2 == 0) FOR(j, sy + 1, W) path.eb(i, j);
    if (i % 2 == 1) FOR_R(j, sy + 1, W) path.eb(i, j);
  }
  FOR_R(j, W) {
    if (j % 2 == 0) FOR(i, sx + 1, H) path.eb(i, j);
    if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i, j);
  }
  return path;
}