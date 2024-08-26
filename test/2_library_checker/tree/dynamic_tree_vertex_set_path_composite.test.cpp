#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/link_cut_tree.hpp"
#include "graph/ds/lct_node_monoid.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"

using mint = modint998;

using Mono = Monoid_Affine<mint>;
using Node = LCT_Node_Monoid<Mono>;

void solve() {
  LL(N, Q);
  Link_Cut_Tree<Node> LCT(N);
  FOR(i, N) {
    mint a, b;
    read(a, b);
    LCT.set(i, {a, b});
  }
  FOR(N - 1) {
    INT(a, b);
    LCT.link(a, b);
  }

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c, d);
      LCT.cut(a, b), LCT.link(c, d);
    }
    if (t == 1) {
      LL(i);
      mint a, b;
      read(a, b);
      LCT.set(i, {a, b});
    }
    if (t == 2) {
      LL(a, b);
      auto f = LCT.prod_path(a, b);
      u32 x;
      read(x);
      mint ans = Mono::eval(f, mint::raw(x));
      print(ans);
    }
  }
}

signed main() {
  solve();
  return 0;
}