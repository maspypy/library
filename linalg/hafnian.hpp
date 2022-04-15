template <typename mint, int LIM = 50>
mint Hufnian(vc<vc<mint>>& B0) {
  // 隣接行列に対して完全マッチングを数える。
  int n = len(B0) / 2;
  using poly = array<mint, LIM / 2>;
  auto add_mul = [&](poly& p, poly& f, poly& g) -> void {
    FOR(i, n) FOR(j, n - i) p[i + j + 1] += f[i] * g[j];
  };
  auto dfs = [&](auto self, vc<vc<poly>> B) -> poly {
    poly res;
    if (len(B) == 0) {
      res[0] = 1;
      return res;
    }
    auto a = B.back();
    B.pop_back();
    auto b = B.back();
    B.pop_back();
    int m = len(B);
    poly p0 = self(self, B);
    FOR(i, m) FOR(j, i) {
      add_mul(B[i][j], a[i], b[j]);
      add_mul(B[i][j], a[j], b[i]);
    }
    poly p1 = self(self, B);
    add_mul(res, a[m], p1);
    FOR(i, n + 1) res[i] += p1[i] - p0[i];
    return res;
  };
  vv(poly, B, n + n, n + n);
  FOR(i, n + n) FOR(j, n + n) B[i][j][0] = B0[i][j];
  return dfs(dfs, B)[n];
}
