
// i<=j に対して match(i,j) が定義されているとき極大回文 [L,R) を列挙する
// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c
template <typename F>
vc<pair<int, int>> manacher(int n, F match) {
  assert(n > 0);
  auto f = [&](int i, int j) -> bool {
    if (i > j) return 0;
    assert((i + j) % 2 == 0);
    if (i & 1) return 1;
    return match(i / 2, j / 2);
  };
  vector<int> dp(2 * n - 1);
  int i = 0, j = 0;
  while (i < 2 * n - 1) {
    while (i - j >= 0 && i + j < 2 * n - 1 && f(i - j, i + j)) ++j;
    dp[i] = j;
    int k = 1;
    while (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) { dp[i + k] = min(j - k, dp[i - k]), ++k; }
    i += k, j = max(j - k, 0);
  }
  vc<pair<int, int>> res;
  FOR(i, len(dp)) {
    if (dp[i] == 0) continue;
    int l = ceil<int>(i - dp[i] + 1, 2);
    int r = floor<int>(i + dp[i] - 1, 2);
    if (l <= r) res.eb(l, r + 1);
  }
  return res;
}

// 極大回文 [L, R) を列挙する
template <typename STRING>
vc<pair<int, int>> manacher(STRING s) {
  int n = len(s);
  assert(n > 0);
  return manacher(n, [&](int i, int j) -> bool { return s[i] == s[j]; });
}
