#define PROBLEM "https://atcoder.jp/contests/arc157/tasks/arc157_a"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/eulerwalk.hpp"

void solve() {
  LL(N, A, B, C, D);
  Graph<bool, 1> G(2);
  FOR(A) G.add(0, 0);
  FOR(B) G.add(0, 1);
  FOR(C) G.add(1, 0);
  FOR(D) G.add(1, 1);
  G.build();
  auto vs = euler_walk(G).fi;
  Yes(!vs.empty());
}

signed main() {
  solve();
  return 0;
}
