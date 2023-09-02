#define PROBLEM "https://atcoder.jp/contests/abc260/tasks/abc260_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/find_C4.hpp"

void solve() {
  LL(S, T, M);
  Graph<int, 0> G(S + T);
  G.read_graph(M);
  auto [a, b, c, d] = find_C4(G);
  if (a == -1) return print(-1);
  print(1 + a, 1 + b, 1 + c, 1 + d);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}