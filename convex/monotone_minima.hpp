
// select(i,j,k) : (i,j) -> (i,k) を行うかどうか
template <typename F>
vc<int> monotone_minima(int H, int W, F select) {
  vc<int> min_col(H);
  auto dfs = [&](auto& dfs, int x1, int x2, int y1, int y2) -> void {
    if (x1 == x2) return;
    int x = (x1 + x2) / 2;
    int best_y = y1;
    for (int y = y1 + 1; y < y2; ++y) {
      if (select(x, best_y, y)) best_y = y;
    }
    min_col[x] = best_y;
    dfs(dfs, x1, x, y1, best_y + 1);
    dfs(dfs, x + 1, x2, best_y, y2);
  };
  dfs(dfs, 0, H, 0, W);
  return min_col;
}