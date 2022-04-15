#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/group_add.hpp"
#include "ds/segtree.hpp"
#include "graph/treegroup.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph G(N);
  G.read_tree(0, 0);

  HLD<Graph<int>> hld(G);
  using Group = Group_Add<ll>;
  TreeGroup<decltype(hld), Group, false, true, false> TG(hld, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TG.set(v, A[v]);
    } else {
      LL(u, v);
      print(TG.prod_path(u, v));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
