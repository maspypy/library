#include "string/suffixarray.hpp"

/*
dp[l][r] := S[l:r] が昇順で何番目か？というテーブルを返す。
O(N^2)
*/
template <typename STRING>
vc<vc<int>> sort_all_substring(STRING S) {
  int n = len(S);
  SuffixArray sa(S);
  auto& SA = sa.SA;
  auto& LCP = sa.LCP;
  int nxt = 0;
  vv(int, DP, n, n + 1, -1);
  FOR(i, len(SA)) {
    auto L = SA[i];
    FOR3(k, 1, n - L + 1) {
      int R = L + k;
      if (i > 0 && LCP[i - 1] >= k)
        DP[L][R] = DP[SA[i - 1]][SA[i - 1] + k];
      else
        DP[L][R] = nxt++;
    }
  }
  return DP;
}

// 長さの上限あり
// (開始位置、長さ) に対してソート順を埋める
template <typename STRING>
vc<vc<int>> sort_all_substring_limit(STRING S, ll LIM) {
  int n = len(S);
  SuffixArray sa(S);
  auto& SA = sa.SA;
  auto& LCP = sa.LCP;
  int nxt = 0;
  vv(int, DP, n, LIM + 1, -1);
  FOR(i, len(SA)) {
    auto L = SA[i];
    FOR3(k, 1, min(n - L, LIM) + 1) {
      int R = L + k;
      if (i > 0 && LCP[i - 1] >= k)
        DP[L][R - L] = DP[SA[i - 1]][k];
      else
        DP[L][R - L] = nxt++;
    }
  }
  return DP;
}