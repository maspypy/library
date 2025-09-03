#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/maxflow.hpp"

void solve() {
  LL(N, M);
  MaxFlow<int> G(N, 0, N - 1);
  FOR(M) {
    LL(a, b, c);
    G.add(a, b, c);
  }
  print(G.flow());
}

signed main() {
  solve();
  return 0;
}
