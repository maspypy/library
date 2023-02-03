#include "graph/base.hpp"
#include "random/base.hpp"

template <int DIRECTED>
Graph<int, DIRECTED> random_graph(int n, bool simple) {
  Graph<int, DIRECTED> G(n);
  vc<pi> cand;
  FOR(a, n) FOR(b, n) {
    if (simple && a == b) continue;
    if (!DIRECTED && a > b) continue;
    cand.eb(a, b);
  }
  int m = RNG(0, len(cand) + 1);
  set<int> ss;
  FOR(m) {
    while (1) {
      int i = RNG(0, len(cand));
      if (simple && ss.count(i)) continue;
      ss.insert(i);
      auto [a, b] = cand[i];
      G.add(a, b);
      break;
    }
  }
  G.build();
  return G;
}