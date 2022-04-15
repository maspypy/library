template <bool CALC_ALL, typename STRING>
vector<int> longest_palindrome(STRING s) {
  if (CALC_ALL) {
    int n = len(s);
    assert(n > 0);
    s.resize(2 * n - 1);
    FOR_R(i, n) s[2 * i] = s[i];
    FOR(i, n - 1) s[2 * i + 1] = '-';
  }
  vector<int> A(len(s));
  int i = 0, j = 0;
  while (i < len(s)) {
    while (i - j >= 0 && i + j < len(s) && s[i - j] == s[i + j]) ++j;
    A[i] = j;
    int k = 1;
    while (i - k >= 0 && i + k < len(s) && k + A[i - k] < j) {
      A[i + k] = A[i - k];
      ++k;
    }
    i += k, j -= k;
  }
  if (CALC_ALL) {
    FOR(i, len(A)) {
      if (!((i ^ A[i]) & 1)) A[i]--;
    }
  } else {
    for (auto&& x: A) x = 2 * x - 1;
  }
  return A;
}
