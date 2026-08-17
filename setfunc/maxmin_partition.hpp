#include "other/bit.hpp"

// https://codeforces.com/blog/entry/153948?#comment-1367191
// O(n 2^n)
template <typename WT>
WT maxmin_partition(int K, vc<WT> A) {
  int N = len(A);
  if (N < K) return 0;
  assert(1 <= K && K <= N);
  vc<WT> S(1 << N);
  FOR(i, N) FOR(s, 1 << i) S[s | 1 << i] = S[s] + A[i];

  WT ANS = 0;
  int full = full_mask(N);
  using P = pair<int, WT>;
  vc<P> dp(1 << N);
  for (int s = 0; s < (1 << N); ++s) {
    int other = full ^ s;
    auto [k, w] = dp[s];
    WT W = S[other] + w;
    if (k == K - 1) {
      chmax(ANS, W);
      continue;
    }
    while (other) {
      int i = lowbit(other);
      other &= other - 1;
      int t = s | 1 << i;
      WT x = w + A[i];
      P nxt = (x * (K - k) >= W ? P(k + 1, 0) : P(k, x));
      chmax(dp[t], nxt);
    }
  }
  return ANS;
}
