#include "string/suffix_array.hpp"

// 最短 border の長さ. なかったら R-L. O(sqrt(N)).
// https://codeforces.com/contest/1043/problem/G
// N=Q=200_000, 1.2sec
int substring_shortest_border(Suffix_Array<true>& X, int L, int R) {
  /*
  border の border は border なので，shortest border B は borderless.
  S における B の occurrence は重複しない.
  よって B を prefix に持つ文字列は高々 O(N/|B|) である.
  これは suffix array における近傍を見れば見つかる.
  */
  int N = len(X.SA);
  int K = sqrt(len(X.SA)) / 2;
  FOR(n, 1, K + 1) {
    if (X.lcp(L, R - n) >= n) return n;
  }
  int ANS = R - L;
  int idx = X.ISA[L];
  int lcp = infty<int>;
  FOR(i, idx + 1, N) {
    chmin(lcp, X.LCP[i - 1]);
    if (lcp <= K) break; // これで勝手に O(sqrt(N)) になる.
    int M = X.SA[i];
    if (L < M && M < R && R - M <= lcp) chmin(ANS, R - M);
  }
  lcp = infty<int>;
  FOR_R(i, idx) {
    chmin(lcp, X.LCP[i]);
    if (lcp <= K) break; // これで勝手に O(sqrt(N)) になる.
    int M = X.SA[i];
    if (L < M && M < R && R - M <= lcp) chmin(ANS, R - M);
  }
  return ANS;
}
