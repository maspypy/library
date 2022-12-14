#include "string/suffix_array.hpp"

template <typename STRING>
tuple<int, int, int, int> longest_common_substring(STRING& S, STRING& T) {
  int dummy = max<int>(*max_element(all(S)), *max_element(all(T))) + 1;
  STRING ST;
  for (auto&& x: S) ST.push_back(x);
  ST.push_back(dummy);
  for (auto&& x: T) ST.push_back(x);
  Suffix_Array X(ST);
  auto& SA = X.SA;
  auto& LCP = X.LCP;

  tuple<int, int, int, int> res = {0, 0, 0, 0};
  int n = 0;
  FOR(i, len(ST) - 1) {
    if ((SA[i] < len(S)) != (SA[i + 1] < len(S))) {
      if (chmax(n, LCP[i])) {
        int a = SA[i];
        int b = SA[i + 1] - len(S) - 1;
        res = {a, a + n, b, b + n};
      }
    }
  }
  return res;
}