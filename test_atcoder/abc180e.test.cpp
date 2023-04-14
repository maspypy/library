#define PROBLEM "https://atcoder.jp/contests/abc180/tasks/abc180_e"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/minimum_hamiltonian_cycle.hpp"

void solve() {
  LL(N);
  using T = tuple<int, int, int>;
  VEC(T, dat, N);
  Graph<int, 1> G(N);
  FOR(i, N) FOR(j, N) {
    if (i == j) continue;
    auto [a, b, c] = dat[i];
    auto [p, q, r] = dat[j];
    G.add(i, j, abs(p - a) + abs(q - b) + max(0, r - c));
  }
  G.build();

  auto [cost, P] = minimum_hamiltonian_cycle<int>(G);
  print(cost);
}

signed main() {
  solve();
  return 0;
}