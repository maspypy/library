// 長さ n の非負整数列で、総和が k のものを全部生成する
vc<vc<int>> generate_multisets(int n, int k) {
  vc<vc<int>> res;
  vc<int> A(n);
  auto dfs = [&](auto self, ll p, ll s) -> void {
    if (p == n - 1) {
      A[p] = s;
      res.eb(A);
      return;
    }
    FOR(x, s + 1) {
      A[p] = x;
      self(self, p + 1, s - x);
    }
  };
  dfs(dfs, 0, k);
  return res;
}
