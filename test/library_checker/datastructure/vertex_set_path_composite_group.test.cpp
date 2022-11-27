#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/ds/treegroup.hpp"
#include "alg/monoid/affine.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  using Mono = Monoid_Affine<mint>;
  using E = Mono::value_type;
  vc<E> A(N);
  FOR(i, N) {
    LL(a, b);
    A[i] = mp(mint(a), mint(b));
  }

  Graph<int> G(N);
  G.read_tree(0, 0);

  TREE tree(G);
  TreeGroup<decltype(tree), Mono, false, true, false> TG(tree, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, c, d);
      TG.set(v, E({mint(c), mint(d)}));
    } else {
      LL(u, v, x);
      auto e = TG.prod_path(u, v);
      print(e.fi * mint(x) + e.se);
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
