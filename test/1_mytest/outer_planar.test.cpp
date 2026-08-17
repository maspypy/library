#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/outerplanar.hpp"

void test() {
  int N = RNG(3, 100);
  auto edges = random_outerplanar(N);
  Graph<int, 0> G(N);
  for (auto& [a, b] : edges) G.add(a, b);
  G.build();
  auto C = hamiltonian_cycle_outerplanar(G);
  assert(!C.empty());
  assert(check_outerplanar(C, G));
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(10000) test();
  solve();
}