#include "graph/centroid.hpp"
#include "poly/convolution.hpp"

template<typename Graph>
vi tree_all_distances(Graph& G){
  // frequency table of distance of all directed pairs. 
  // sum of result array = N^2
  
  assert(G.is_prepared());
  assert(!G.is_directed());

  CentroidDecomposition CD(G);

  ll N = G.N;
  vi ANS(N);
  FOR(root, N) {
    auto data = CD.collect(root, 0);
    FOR(i, len(data)) {
      int n = 0;
      FOR(j, len(data[i])) chmax(n, data[i][j].se + 1);
      vi A(n);
      FOR(j, len(data[i])) A[data[i][j].se]++;
      auto B = convolution(A, A);
      FOR(j, min(N, len(B))) ANS[j] += (i == 0 ? B[j] : -B[j]);
    }
  }
  return ANS;
}