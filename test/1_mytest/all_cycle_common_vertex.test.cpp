#include "my_template.hpp"
// #include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/all_cycle_common_vertex.hpp"

#include "random/base.hpp"

vc<int> naive(Graph<int, 1> G) {
  int N = G.N;
  vc<int> ANS;
  auto dag = [&](vc<int> V) -> bool {
    Graph<int, 1> H = G.rearrange(V);
    return V.empty() || (!toposort(H).empty());
  };
  vc<int> V;
  FOR(i, N) V.eb(i);
  if (dag(V)) return {};
  FOR(v, N) {
    V.erase(find(all(V), v));
    if (dag(V)) ANS.eb(v);
    V.eb(v);
  }
  return ANS;
}

void test() {
  FOR(1 << 18) {
    int N = RNG(1, 4);
    Graph<int, 1> G(N);
    int prob = RNG(0, 100);
    FOR(a, N) FOR(b, N) {
      if (a == b) continue;
      if (RNG(0, 100) < prob) G.add(a, b);
    }
    G.build();
    auto ANS1 = all_cycle_common_vertex(G, 0);
    auto ANS2 = naive(G);
    sort(all(ANS1));
    sort(all(ANS2));
    // G.debug();
    // SHOW(ANS1, ANS2);
    assert(ANS1 == ANS2);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
}
