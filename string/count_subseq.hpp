#include "ds/hashmap.hpp"

template <typename mint, typename CHAR, typename STRING, int LOG = 20>
mint count_subseq(STRING S) {
  static HashMap<int, LOG> IDX;
  ll N = len(S);
  vc<mint> DP(N + 1);
  DP[0] = 1;
  FOR(i, N) {
    CHAR c = S[i];
    DP[i + 1] = DP[i] + DP[i];
    int k = IDX.get(c, -1);
    if (k != -1) DP[i + 1] -= DP[k];
    IDX[c] = i;
  }
  return DP.back();
}
