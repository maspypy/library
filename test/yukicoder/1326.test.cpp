#define PROBLEM "https://yukicoder.me/problems/no/1326"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/block_cut.hpp"
#include "graph/ds/treeabelgroup.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, M);
  Graph<int> G(N);
  G.read_graph(M);
  auto BCT = block_cut<decltype(G)>(G);
  TREE<decltype(BCT)> tree(BCT);

  vc<int> dat(tree.N);
  FOR(v, N) if (BCT.deg(v) > 1) dat[v] = 1;
  TreeAbelGroup<decltype(tree), Monoid_Add<int>, 0, 1, 0> TA(tree, dat);

  LL(Q);
  FOR(Q) {
    LL(x, y);
    --x, --y;
    if (x == y) {
      print(0);
      continue;
    }
    ll k = TA.prod_path(x, y);
    if (BCT.deg(x) > 1) --k;
    if (BCT.deg(y) > 1) --k;
    print(k);
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
