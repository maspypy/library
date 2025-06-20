
// 始点を返す
template <typename STRING>
int minimum_cyclic_shift(STRING S) {
  int n = len(S), i = 0, ans = 0;
  FOR(i, n) S.push_back(S[i]);
  while (i < n) {
    ans = i;
    int j = i + 1, k = i;
    while (j < i + n && S[k] <= S[j]) {
      if (S[k] < S[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) i += j - k;
  }
  return ans;
}
