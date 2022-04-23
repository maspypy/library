// 極大回文 [L, R) を列挙する
template <typename STRING>
vc<pair<int, int>> manacher(STRING s) {
  int n = len(s);
  assert(n > 0);
  s.resize(2 * n - 1);
  FOR_R(i, n) s[2 * i] = s[i];
  FOR(i, n - 1) s[2 * i + 1] = '~';
  vector<int> dp(len(s));
  int i = 0, j = 0;
  while (i < len(s)) {
    while (i - j >= 0 && i + j < len(s) && s[i - j] == s[i + j]) ++j;
    dp[i] = j;
    int k = 1;
    while (i - k >= 0 && i + k < len(s) && k + dp[i - k] < j) {
      dp[i + k] = dp[i - k];
      ++k;
    }
    i += k, j -= k;
  }
  FOR(i, len(dp)) if (!((i ^ dp[i]) & 1))-- dp[i];
  vc<pair<int, int>> res;
  res.reserve(len(dp));
  FOR(i, len(dp)) {
    if (dp[i] == 0) continue;
    int l = (i - dp[i] + 1) / 2;
    int r = (i + dp[i] + 1) / 2;
    res.eb(l, r);
  }
  return res;
}
