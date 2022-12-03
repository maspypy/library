#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"
#include "graph/ds/tree_monoid.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  using Mono = Monoid_Affine<mint>;
  using E = pair<mint, mint>;
  vc<E> A(N);
  FOR(i, N) {
    LL(a, b);
    A[i] = E({a, b});
  }

  Graph<int> G(N);
  G.read_tree(0, 0);

  TREE tree(G);
  Tree_Monoid<decltype(tree), Mono, false> TM(tree, A);

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(v, c, d);
      TM.set(v, E({mint(c), mint(d)}));
    } else {
      LL(u, v, x);
      auto e = TM.prod_path(u, v);
      print(Mono::eval(e, mint(x)));
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
