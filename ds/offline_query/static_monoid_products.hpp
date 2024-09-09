// f(q, Lprod, Rprod)
// f 以外で呼ばれるものはすべて単項追加
// https://qoj.ac/contest/1784/problem/9245
template <typename Mono, typename T, typename F>
void static_monoid_products(vc<T>& A, vc<pair<int, int>>& query, F f) {
  int N = len(A), Q = len(query);
  vvc<int> IDS(N);
  FOR(q, Q) {
    auto [L, R] = query[q];
    if (L == R) { f(q, Mono::unit(), Mono::unit()); }
    elif (R <= L + 16) {
      T ans = A[L];
      FOR(i, L + 1, R) ans = Mono::op(ans, A[i]);
      f(q, ans, Mono::unit());
    }
    else {
      --R;
      int k = topbit(L ^ R);
      int M = R >> k << k;
      IDS[M].eb(q);
    }
  }
  vc<T> dp(N + 1);

  FOR(M, N) {
    auto& I = IDS[M];
    if (I.empty()) continue;
    int min_a = M, max_b = M;
    for (int q: I) {
      auto [a, b] = query[q];
      min_a = min(min_a, a), max_b = max(max_b, b);
    }
    // 累積積の計算
    dp[M] = Mono::unit();
    for (int i = M; i > min_a; --i) dp[i - 1] = Mono::op(A[i - 1], dp[i]);
    for (int i = M; i < max_b; ++i) dp[i + 1] = Mono::op(dp[i], A[i]);
    // 答の計算
    for (int q: I) {
      auto [a, b] = query[q];
      f(q, dp[a], dp[b]);
    }
  }
}
