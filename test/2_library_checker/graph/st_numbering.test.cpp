#define PROBLEM "https://judge.yosupo.jp/problem/st_numbering"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/st_numbering.hpp"

void solve() {
  LL(N, M, s, t);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto p = st_numbering(G, s, t);
  if (p.empty()) {
    No();
  } else {
    Yes();
    print(p);
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
