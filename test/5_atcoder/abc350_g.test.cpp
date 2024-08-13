#define PROBLEM "https://atcoder.jp/contests/abc350/tasks/abc350_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/link_cut_tree.hpp"
#include "graph/ds/lct_node_base.hpp"

using Node = LCT_Node_Base;
void solve() {
  LL(N, Q);
  Link_Cut_Tree<Node> LCT(N);

  ll X = 0;

  FOR(Q) {
    LL(a, b, c);
    ll A = 1 + ((a * (1 + X)) % 998244353) % 2;
    ll B = 1 + ((b * (1 + X)) % 998244353) % N;
    ll C = 1 + ((c * (1 + X)) % 998244353) % N;
    // print(A, B, C);
    if (A == 1) {
      ll u = B, v = C;
      --u, --v;
      LCT.link(u, v);
    }
    if (A == 2) {
      ll u = B, v = C;
      --u, --v;
      ll ans = [&]() -> ll {
        if (LCT.get_root(u) != LCT.get_root(v)) { return 0; }
        ll x = LCT.jump(u, v, 1);
        ll y = LCT.jump(v, u, 1);
        if (x != y) return 0;
        return 1 + x;
      }();
      print(ans);
      X = ans;
    }
  }
}

signed main() {
  solve();
  return 0;
}
