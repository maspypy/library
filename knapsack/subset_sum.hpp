// 作れるならば復元、そうでないならば {} を返す
// O(N max(vals)) 時間
template <typename INT>
vc<int> subset_sum(vc<INT>& vals, int target) {
  if (target <= 0) return {};
  int n = len(vals);
  int mx = MAX(vals);
  int b = 0, sb = 0;
  while (b < n && sb + vals[b] <= target) { sb += vals[b++]; }
  if (b == n && sb != target) return {};

  int off = target - mx + 1;
  vc<int> dp(2 * mx, -1);
  vv(int, PAR, n, 2 * mx, -1);
  dp[sb - off] = b;
  FOR3(i, b, n) {
    auto newdp = dp;
    auto& par = PAR[i];
    int a = vals[i];
    FOR(j, mx) {
      if (chmax(newdp[j + a], dp[j])) { par[j + a] = -2; }
    }
    FOR3_R(j, mx, 2 * mx) {
      FOR3_R(k, max(dp[j], 0), newdp[j]) {
        if (chmax(newdp[j - vals[k]], k)) par[j - vals[k]] = k;
      }
    }
    swap(dp, newdp);
  }
  if (dp[mx - 1] == -1) return {};
  vc<bool> use(n);
  int i = n - 1, j = mx - 1;
  while (i >= b) {
    int p = PAR[i][j];
    if (p == -2) {
      use[i] = !use[i];
      j -= vals[i--];
    }
    elif (p == -1) { --i; }
    else {
      use[p] = !use[p];
      j += vals[p];
    }
  }
  while (i >= 0) {
    use[i] = !use[i];
    --i;
  }
  vc<int> I;
  FOR(i, n) if (use[i]) I.eb(i);

  ll sm = 0;
  for (auto&& i: I) sm += vals[i];
  assert(sm == target);

  return I;
}