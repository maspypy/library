#pragma once

// select(i,j,k) は (i,j) -> (i,k) を行うかどうか
// 残念ながら monotone minima より高速な場合が存在しない説がある
// https://codeforces.com/contest/1423/problem/M
template <typename F>
vc<int> smawk(int H, int W, F select) {
  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int> {
    int N = len(X);
    if (N == 0) return {};
    vc<int> YY;
    for (auto&& y: Y) {
      while (len(YY)) {
        int py = YY.back(), x = X[len(YY) - 1];
        if (!select(x, py, y)) break;
        YY.pop_back();
      }
      if (len(YY) < len(X)) YY.eb(y);
    }
    vc<int> XX;
    FOR(i, 1, len(X), 2) XX.eb(X[i]);
    vc<int> II = dfs(dfs, XX, YY);
    vc<int> I(N);
    FOR(i, len(II)) I[i + i + 1] = II[i];
    int p = 0;
    FOR(i, 0, N, 2) {
      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);
      int best = Y[p];
      while (Y[p] < LIM) {
        ++p;
        if (select(X[i], best, Y[p])) best = Y[p];
      }
      I[i] = best;
    }
    return I;
  };
  vc<int> X(H), Y(W);
  iota(all(X), 0), iota(all(Y), 0);
  return dfs(dfs, X, Y);
}