/*
T 値の 2 変数関数 f(i,j) が monotone だとする。
各 i に対して、f が min になる j および、f(i,j) の組を返す。
f を O((H+W) logH) 回計算する。
*/
template <typename T, typename F>
vc<pair<int, T>> monotone_minima(int H, int W, F f) {
  using P = pair<int, T>;
  vc<P> dp(H);
  // closed
  auto dfs = [&](auto self, int x1, int x2, int y1, int y2) -> void {
    if (x1 > x2) return;
    int x = (x1 + x2) / 2;
    P best = {-1, 0};
    FOR3(y, y1, y2 + 1) {
      T cost = f(x, y);
      if (best.fi == -1 || cost < best.se) best = {y, cost};
    }
    dp[x] = best;
    int y = best.fi;
    if (x1 <= x - 1) self(self, x1, x - 1, y1, y);
    if (x + 1 <= x2) self(self, x + 1, x2, y, y2);
  };
  dfs(dfs, 0, H - 1, 0, W - 1);
  return dp;
}