#include "geo/angle_sort.hpp"

/*
点群は distinct
edge(i,j): i->j で遷移していくと偏角昇順（strict）な辺の列になる順
典型的には v を固定して v->v を作ると凸多角形になる
通常は退化ケースは別途処理し，非退化を保証するために使った辺が3個以上かのフラグを持つ
*/
template <typename P>
vc<pair<int, int>> convex_polygon_dp_order(vc<P> A) {
  int N = len(A);
  vc<pair<int, int>> E;
  FOR(i, N) FOR(j, N) {
    if (i == j) continue;
    assert(A[i] != A[j]);
    E.eb(i, j);
  }

  sort(all(E), [&](auto& X, auto& Y) -> bool {
    auto [a, b] = X;
    auto [c, d] = Y;
    int k = angle_comp_3(A[b] - A[a], A[d] - A[c]);
    if (k == -1) return true;
    if (k == 1) return false;
    P dir = A[b] - A[a];
    return dir.dot(A[b] - A[d]) > 0;
  });
  return E;
}