#include "string/suffix_array.hpp"

// ANS[i] := length of lex-max suffix of S[0,i), O(|S|) time
// https://www.codechef.com/START137A/problems/CABABAA
vc<int> lex_max_suffix_for_all_prefix(string S) {
  // suffix array 順をもとにして1文字ずつ消していく.
  // 手前のものに抜かされるのは, 自分より長いものの prefix になるとき.
  // 一度抜かされたらもう復活することはない.
  int N = len(S);
  Suffix_Array X(S);
  auto &SA = X.SA, &LCP = X.LCP;
  vvc<int> rm(N);
  vc<pair<int, int>> st;
  FOR(i, N) {
    int j = SA[i];
    int k = (i == 0 ? infty<int> : LCP[i - 1]);
    while (len(st) && st.back().fi > j) {
      chmin(k, st.back().se);
      POP(st);
    }
    if (len(st)) { rm[j + k].eb(j); }
    st.eb(j, k);
  }
  int p = N - 1;
  vc<int> ANS(N + 1);
  vc<bool> ng(N);
  FOR_R(i, 1, N + 1) {
    while (ng[SA[p]] || i <= SA[p]) --p;
    ANS[i] = i - SA[p];
    for (auto& j: rm[i - 1]) ng[j] = 1;
  }
  return ANS;
}
