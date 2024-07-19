#include "ds/wavelet_matrix/wavelet_matrix.hpp"

// https://codeforces.com/blog/entry/111625
struct Prefix_Substring_LCS {
  int N, M;
  vc<Wavelet_Matrix<int, true>> WM;

  template <typename STRING>
  Prefix_Substring_LCS(STRING S, STRING T) {
    build(S, T);
  }

  template <typename STRING>
  void build(STRING S, STRING T) {
    N = len(S), M = len(T);
    vv(int, dph, N + 1, M + 1);
    vv(int, dpv, N + 1, M + 1);
    FOR(j, M + 1) dph[0][j] = j;
    FOR(i, 1, N + 1) FOR(j, 1, M + 1) {
      bool same = S[i - 1] == T[j - 1];
      int a = dph[i - 1][j], b = dpv[i][j - 1];
      dph[i][j] = (same ? b : max(a, b));
      dpv[i][j] = (same ? a : min(a, b));
    }
    FOR(i, N + 1) { WM.eb(Wavelet_Matrix<int, true>(dph[i])); }
  }

  // LCS(S[0:n], T[L:R])
  int query(int n, int L, int R) { return WM[n].count(L + 1, R + 1, 0, L + 1); }
};
