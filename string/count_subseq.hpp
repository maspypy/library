#include "ds/hashmap.hpp"

// https://noshi91.hatenablog.com/entry/2023/02/26/135340
template <typename mint, typename STRING, int LOG = 20>
mint count_subseq(STRING S) {
  static HashMap<mint, LOG> dp;
  mint sm = 1;
  for (auto&& x: S) {
    mint d = dp[x];
    dp[x] = sm;
    sm += sm - d;
  }
  return sm;
}