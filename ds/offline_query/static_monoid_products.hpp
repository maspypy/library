
template <typename Mono, typename T>
vc<T> static_monoid_products(vc<T>& A, vc<pair<int, int>>& query) {
  int N = len(A), Q = len(query);

  vc<T> ANS(Q);
  vvc<int> IDS(N);
  FOR(q, Q) {
    auto [L, R] = query[q];
    if (L == R) { ANS[q] = Mono::unit(); }
    elif (R <= L + 32) {
      ANS[q] = A[L];
      FOR(i, L + 1, R) ANS[q] = Mono::op(ANS[q], A[i]);
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
      ANS[q] = Mono::op(dp[a], dp[b]);
    }
  }
  return ANS;
}
