#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_polynomial"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/chromatic.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto f = chromatic_polynomial<mint, 20>(G);
  print(f);
}

signed main() {
  solve();
  return 0;
}
