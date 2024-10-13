#include "graph/base.hpp"

template <typename Gr, typename F>
void enumerate_triangle(Gr& G, F query) {
  int N = G.N;
  Graph<int, 1> H(N);
  set<pair<int, int>> done;
  auto add = [&](int a, int b) -> void {
    pair<int, int> p = {a, b};
    if (done.count(p)) return;
    done.insert(p);
    H.add(a, b);
  };
  for (auto&& e: G.edges) {
    // 注意：次数比較だけだと DAG にならず、サイクルができてしまう
    if (mp(G.deg(e.frm), e.frm) < mp(G.deg(e.to), e.to))
      add(e.frm, e.to);
    else
      add(e.to, e.frm);
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
