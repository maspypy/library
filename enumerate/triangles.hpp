#include "graph/base.hpp"

template <typename Gr, typename F>
void enumerate_triangles(Gr& G, F query) {
  int N = G.N;
  Graph<int, 1> H(N);
  for (auto&& e: G.edges) {
    // 注意：次数比較だけだと DAG にならず、サイクルができてしまう
    if (mp(G.deg(e.frm), e.frm) < mp(G.deg(e.to), e.to))
      H.add(e.frm, e.to);
    else
      H.add(e.to, e.frm);
  }
  H.build();

  vc<bool> table(N);
  FOR(a, N) {
    for (auto&& e: H[a]) { table[e.to] = 1; }
    for (auto&& e: H[a]) {
      int b = e.to;
      for (auto&& f: H[b]) {
        int c = f.to;
        if (table[c]) query(a, b, c);
      }
    }
    for (auto&& e: H[a]) { table[e.to] = 0; }
  }
}
