#include "graph/centroid.hpp"
#include "poly/convolution.hpp"

// frequency table of distance of all directed pairs.

// sum of result array = N^2

template <typename GT>
vi tree_all_distances(GT& G) {
  assert(G.is_prepared());
  assert(!G.is_directed());
  Centroid_Decomposition CD(G);

  ll N = G.N;
  vi ANS(N);
  FOR(root, N) {
    auto [V, dp, grp] = CD.collect_dist(root);
    int n = len(V);
    auto calc = [&](vc<int> vals, int sgn) -> void {
      if (vals.empty()) return;
      int mx = MAX(vals);
      vi A(mx + 1);
      for (int x: vals) A[x]++;
      A = convolution(A, A);
      FOR(j, len(A)) if (j < N) ANS[j] += sgn * A[j];
    };

    calc(dp, +1);
    vc<int> vals;
    FOR(i, 1, n) {
      if (grp[i] != grp[i - 1]) { calc(vals, -1), vals.clear(); }
      vals.eb(dp[i]);
    }
    calc(vals, -1);
  }
  return ANS;
}
