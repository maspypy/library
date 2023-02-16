#include "string/suffix_array.hpp"

// dp[i][j]：S[i:i+j) の rank
template <typename STRING>
vvc<int> sort_substrings(STRING& S, int max_len = -1) {
  int n = len(S);
  if (max_len == -1) max_len = n;
  Suffix_Array sa(S);
  auto& SA = sa.SA;
  auto& LCP = sa.LCP;
  int nxt = 0;
  vv(int, dp, n, max_len + 1, -1);
  FOR(i, len(SA)) {
    auto L = SA[i];
    FOR(k, 1, min(n - L, max_len) + 1) {
      int R = L + k;
      if (i > 0 && LCP[i - 1] >= k)
        dp[L][R - L] = dp[SA[i - 1]][k];
      else
        dp[L][R - L] = nxt++;
    }
  }
  return dp;
}