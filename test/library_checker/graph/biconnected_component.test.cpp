#define PROBLEM "https://yukicoder.me/problems/no/1326"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/biconnected_component.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);

  auto T = block_cut_tree<decltype(G)>(G);

  print(T.N - N);
  FOR(k, N, T.N) {
    vc<int> ANS;
    for (auto&& e: T[k]) ANS.eb(e.to);
    print(len(ANS), ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}