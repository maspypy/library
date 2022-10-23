#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/max_matching_size.hpp"
#include "flow/bipartite.hpp"

template <typename GT>
int max_matching_size(GT& G) {
  using mint = modint61;
  assert(!G.is_directed());
  int N = G.N;
  vv(mint, tutte, N, N);
  for (auto&& e: G.edges) {
    mint x = RNG(mint::get_mod());
    int i = e.frm, j = e.to;
    tutte[i][j] += x;
    tutte[j][i] -= x;
  }
  return matrix_rank(tutte) / 2;
}

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
      int b = max_matching_size(G);
      assert(a == b);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test_bipartite();
  solve();

  return 0;
}
