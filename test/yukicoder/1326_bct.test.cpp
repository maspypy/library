#define PROBLEM "https://yukicoder.me/problems/no/1326"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/biconnected_component.hpp"
#include "graph/treeabelgroup.hpp"
#include "alg/group_add.hpp"

void solve() {
  LL(N, M);
  Graph<int> G(N);
  G.read_graph(M);
  Biconnected_Component<decltype(G)> BC(G);

  auto T = BC.BCT();
  TREE tree(T);

  vc<int> dat(T.N);
  FOR(v, N) if (BC.is_articulation(v)) { dat[BC.BCT_idx_v(v)]++; }
  TreeAbelGroup<decltype(tree), Group_Add<int>, 0, 1, 0> TA(tree, dat);

  LL(Q);
  FOR(Q) {
    LL(x, y);
    --x, --y;
    auto a = BC.BCT_idx_v(x);
    auto b = BC.BCT_idx_v(y);
    if (a == b) {
      print(0);
      continue;
    }
    ll k = TA.prod_path(a, b);
    if (BC.is_articulation(x)) --k;
    if (BC.is_articulation(y)) --k;
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
