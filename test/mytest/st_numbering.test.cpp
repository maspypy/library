#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/st_numbering.hpp"
#include "random/random_graph.hpp"

void test() {
  // valid な output になっていることは最後にチェックしているので
  // invalid と言われたときに構築不可能であることを確かめればよい
  FOR(N, 2, 20) {
    FOR(100) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<0>(N, false)) { G.add(a, b); };
      G.build();

      auto BCT = block_cut(G);
      UnionFind uf(N);
      for (auto& e: G.edges) uf.merge(e.frm, e.to);
      FOR(s, N) FOR(t, N) {
        auto ST = st_numbering(G, s, t);
        assert((!ST.empty()) == check_st_numbering(G, s, t));
      }
    }
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
  return 0;
}