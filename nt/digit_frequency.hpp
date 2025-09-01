template <typename T = ll, int K = 10>
array<T, K> digit_frequency_vector(vc<int> A, bool include_N) {
  assert(len(A) > 0 && A[0] != '0');
  ll n = len(A);
  vc<T> pw(n + 1, T(1));
  FOR(i, n) pw[i + 1] = pw[i] * K;
  using ARR = array<T, K>;
  ARR dp{}, same{};
  same[A[0]] = 1;
  FOR(i, 1, A[0]) dp[i] = 1;
  T lo_cnt = SUM<T>(dp);
  FOR(i, 1, len(A)) {
    int a = A[i];
    ARR newdp{};
    FOR(k, K) newdp[k] = dp[k] * K + lo_cnt + same[k] * a + (k < a) + (k > 0);
    lo_cnt = lo_cnt * K + a + (K - 1);
    swap(dp, newdp);
    same[a] += 1;
  }
  if (include_N) {
    FOR(k, K) dp[k] += same[k];
  }
  return dp;
}

// [L,R) をすべて 10 進表記したときに各 digit が現れる回数
template <typename T = ll, int K = 10>
array<T, K> digit_frequency(u64 L, u64 R) {
  auto F = [&](u64 N) -> array<T, K> {
    vc<int> A;
    while (N) {
      A.eb(N % K), N /= K;
    }
    reverse(all(A));
    return digit_frequency_vector<T, K>(A, false);
  };
  array<T, K> A = F(R);
  array<T, K> B = F(L);
  FOR(k, K) A[k] -= B[k];
  return A;
}