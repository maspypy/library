#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "mod/modint.hpp"
#include "enumerate/clique.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, X, N);
  mint ANS = 0;
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);

  auto f = [&](vc<int> C) -> void {
    mint p = 1;
    for (auto&& i: C) p *= X[i];
    ANS += p;
  };
  enumerate_clique(G, f);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
