
#include "ds/unionfind/unionfind.hpp"

// 区間は [L, R). 交わりが空でないものを union．
// https://codeforces.com/contest/1209/problem/G1
UnionFind interval_graph_unionfind(int N, vc<int> L, vc<int> R) {
  // 包含のある場合含まれているものをマージして削除する
  // 包含がなくなったら隣接しているものをマージする
  assert(len(L) == N && len(R) == N);
  vc<int> I(N);
  FOR(i, N) I[i] = i;

  sort(all(I), [&](auto& a, auto& b) -> bool {
    if (L[a] != L[b]) return L[a] < L[b];
    return R[a] > R[b];
  });

  UnionFind uf(N);
  vc<int> keep;
  for (auto& j: I) {
    if (!keep.empty()) {
      int i = keep.back();
      if (R[j] <= R[i] && R[j] - L[j] < R[i] - L[i]) {
        uf.merge(i, j);
        continue;
      }
    }
    keep.eb(j);
  }
  FOR(k, len(keep) - 1) {
    int i = keep[k], j = keep[k + 1];
    if (max(L[i], L[j]) < min(R[i], R[j])) uf.merge(i, j);
  }
  return uf;
}
