#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bipartite.hpp"

void solve() {
  LL(L, R, M);
  Graph G;
  FOR_(M) {
    LL(a, b);
    G.add(a, b + L);
  }
  G.build();
  BipartiteMatching BM(G);

  auto match = BM.matching();
  print(len(match));
  for (auto&& [a, b]: match) print(a, b - L);
}

signed main() {
  solve();

  return 0;
}
