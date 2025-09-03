#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/maximum_matching_size.hpp"
#include "flow/bipartite.hpp"

void test_bipartite() {
  FOR(N, 1, 50) {
    FOR(M, RNG(0, N * (N - 1) / 2 + 1)) {
      Graph<bool, 0> G(N);
      FOR(M) {
        int a = RNG(0, N);
        int b = RNG(0, N);
        if (a % 2 == b % 2) continue;
        G.add(a, b);
      }
      G.build();
      BipartiteMatching<decltype(G)> X(G);
      int a = len(X.matching());
      int b = maximum_matching_size(G);
      assert(a == b);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_bipartite();
  solve();

  return 0;
}
