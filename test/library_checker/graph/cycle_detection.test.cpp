#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/find_cycle.hpp"

void solve() {
  LL(N, M);
  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);

  auto C = find_cycle(G, true);
  if (len(C) == 0) {
    print(-1);
  } else {
    print(len(C));
    for (auto&& i: C) print(i);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}