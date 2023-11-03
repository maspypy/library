#include "graph/centroid_decomposition.hpp"
#include "poly/convolution.hpp"

// frequency table of distance of all directed pairs.
// sum of result array = N^2
template <typename GT>
vi tree_all_distances(GT& G) {
  static_assert(!GT::is_directed);
  assert(G.is_prepared());
  int N = G.N;
  vi ANS(N);
  auto f = [&](Graph<int, 1>& G, vc<int>& V, int n1, int n2) -> void {
    int N = G.N;
    vc<int> dist(N);
    FOR(i, N) {
      for (auto& e: G[i]) dist[e.to] = dist[i] + 1;
    }
    int a = 0, b = 0;
    FOR(i, 1, N) { chmax((i <= n1 ? a : b), dist[i]); }
    vi f(a + 1), g(b + 1);
    FOR(i, 1, 1 + n1) f[dist[i]]++;
    FOR(i, 1 + n1, 1 + n1 + n2) g[dist[i]]++;
    f = convolution(f, g);
    FOR(i, len(f)) ANS[i] += f[i] * 2;
  };
  centroid_decomposition_1(G, f);
  ANS[0] = N, ANS[1] = 2 * (N - 1);
  return ANS;
}
