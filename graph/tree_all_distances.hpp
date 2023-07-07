#include "graph/centroid.hpp"
#include "poly/convolution.hpp"

// frequency table of distance of all directed pairs.
// sum of result array = N^2
template <typename Graph>
vi tree_all_distances(Graph& G) {
  assert(G.is_prepared());
  assert(!G.is_directed());
  Centroid_Decomposition CD(G);

  ll N = G.N;
  vi ANS(N);
  FOR(root, N) {
    auto [V, dp, indptr] = CD.collect_dist(root);
    auto calc = [&](vc<int> vals, int sgn) -> void {
      if (vals.empty()) return;
      int mx = MAX(vals);
      vi A(mx + 1);
      for (int x: vals) A[x]++;
      A = convolution(A, A);
      FOR(j, len(A)) if (j < N) ANS[j] += sgn * A[j];
    };

    calc(dp, +1);
    FOR(i, 1, len(indptr) - 1) {
      int l = indptr[i], r = indptr[i + 1];
      calc({dp.begin() + l, dp.begin() + r}, -1);
    }
  }
  return ANS;
}
