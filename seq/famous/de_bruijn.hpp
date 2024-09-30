string de_bruijn(int n) {
  vc<int> a(2 * n, 0);
  string ANS;
  auto dfs = [&](auto& dfs, int t, int p) -> void {
    if (t > n) {
      if (n % p == 0) {
        FOR(j, 1, p + 1) { ANS += '0' + a[j]; }
      }
      return;
    }
    a[t] = a[t - p];
    dfs(dfs, t + 1, p);
    FOR(j, a[t - p] + 1, 2) {
      a[t] = j;
      dfs(dfs, t + 1, t);
    }
  };
  dfs(dfs, 1, 1);
  return ANS;
}