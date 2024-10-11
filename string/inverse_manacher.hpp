#include "ds/unionfind/unionfind.hpp"
#include "other/mex.hpp"

// 各点を中心とする極大回文の長さ (in [1,3,5,...])
// 辞書最小 OR empty
vc<int> inverse_manacher(vc<int> R) {
  for (auto& x: R) assert(x & 1), x = (x + 1) / 2;
  ll N = len(R);
  UnionFind uf(N);
  vvc<int> DIFF(N);
  int i = 0;
  int j = 0;
  while (i < N) {
    while (i >= j && i + j < N) {
      if (R[i] != j) {
        if (j) { uf.merge(i + j, i - j); }
        j += 1;
      } else {
        DIFF[i + j].eb(i - j);
        DIFF[i - j].eb(i + j);
        break;
      }
    }
    if (R[i] != j) return {};
    int k = 1;
    while (i >= k && i + k < N && k + R[i - k] < j) {
      if (R[i + k] != R[i - k]) return {};
      k += 1;
    }
    i += k;
    j -= k;
  }
  vvc<int> vs(N);
  FOR(v, N) vs[uf[v]].eb(v);
  vc<int> ANS(N, -1);
  FOR(v, N) {
    int r = uf[v];
    if (ANS[r] != -1) continue;
    vc<int> tmp;
    for (auto& w: vs[r]) {
      for (auto& to: DIFF[w]) {
        if (ANS[to] != -1) tmp.eb(ANS[to]);
      }
    }
    int x = mex(tmp);
    for (auto& w: vs[r]) ANS[w] = x;
  }
  return ANS;
}