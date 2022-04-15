#include "flow/bipartite.hpp"
#include "graph/toposort.hpp"

// path （頂点列）の vector を返す O(m sqrt(n))
template <typename DAG>
vc<vc<int>> dag_path_cover(DAG& G) {
  assert(G.is_directed());
  int n = G.N;
  auto V = toposort(G);
  vc<int> idx(n);
  FOR(i, n) idx[V[i]] = i;

  // check dag
  for (auto&& e: G.edges) assert(idx[e.frm] < idx[e.to]);

  Graph H(n + n);
  for (auto&& e: G.edges) { H.add(e.frm, e.to + n); }
  H.build();
  BipartiteMatching BM(H);
  auto match = BM.matching();
  vc<int> nxt(n, -1);
  for (auto&& [a, b]: match) {
    if (a > b) swap(a, b);
    nxt[a] = b - n;
  }

  vc<bool> done(n);

  vvc<int> paths;
  for (auto&& v: V) {
    if (done[v]) continue;
    vc<int> P = {v};
    while (1) {
      int w = nxt[P.back()];
      if (w == -1) break;
      P.eb(w);
    }
    for (auto&& x: P) done[x] = 1;
    paths.eb(P);
  }
  return paths;
};