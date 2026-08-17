#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bipartite_matching.hpp"

void solve() {
  LL(L, R, M);
  Graph G(L + R);
  FOR(M) {
    LL(a, b);
    G.add(a, b + L);
  }
  G.build();
  Bipartite_Matching BM(G);

  auto match = BM.matching();
  print(len(match));
  for (auto&& [a, b] : match) print(a, b - L);
}

signed main() {
  solve();

  return 0;
}
