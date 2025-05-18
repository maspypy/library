
// 始点を返す
int minimum_cyclic_shift(string S) {
  int n = len(S), i = 0, ans = 0;
  S += S;
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
