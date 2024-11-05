#include "graph/centroid_decomposition.hpp"
#include "poly/convolution.hpp"

// sum of result array = binom(N,2)
template <typename GT>
vi tree_all_distances(GT& G) {
  assert(G.is_prepared());
  int N = G.N;
  vi ANS(N);
  auto f = [&](vc<int>& par, vc<int>& V, int L1, int R1, int L2, int R2) -> void {
    int N = len(par);
    vc<int> dist(N);
    FOR(i, 1, N) { dist[i] = 1 + dist[par[i]]; }
    int mx = MAX(dist);
    vi f(1 + mx), g(1 + mx);
    FOR(i, L1, R1) f[dist[i]]++;
    FOR(i, L2, R2) g[dist[i]]++;
    while (len(f) && f.back() == 0) POP(f);
    while (len(g) && g.back() == 0) POP(g);
    f = convolution(f, g);
    FOR(i, len(f)) ANS[i] += f[i];
  };
  centroid_decomposition<1>(G, f);
  ANS[1] = N - 1;
  return ANS;
}
