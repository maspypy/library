#define PROBLEM "https://atcoder.jp/contests/abc298/tasks/abc298_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_dp/subtree_depth_sum.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  SubTree_DepthSum<decltype(tree), ll> DP(tree);

  LL(Q);
  FOR(Q) {
    LL(A, B);
    --A, --B;
    ll d = tree.dist(A, B);

    ll ANS = 0;
    if (d == 0) { ANS = DP[A].se; }
    elif (d % 2 == 1) {
      ll A1 = tree.jump(A, B, d / 2);
      ll B1 = tree.jump(B, A, d / 2);
      ANS += DP[A].se;
      ANS -= DP.get(B1, A).se + ll(tree.dist(A, B1)) * DP.get(B1, A).fi;
      ANS += DP[B].se;
      ANS -= DP.get(A1, B).se + ll(tree.dist(B, A1)) * DP.get(A1, B).fi;
    }
    else {
      ll C = tree.jump(A, B, d / 2);
      ll A1 = tree.jump(C, A, 1);
      ll B1 = tree.jump(C, B, 1);
      ANS += DP[A].se;
      ANS -= DP.get(C, A).se + ll(tree.dist(A, C)) * DP.get(C, A).fi;
      ANS += DP[B].se;
      ANS -= DP.get(C, B).se + ll(tree.dist(B, C)) * DP.get(C, B).fi;
      ll x = 0;
      ll n = 0;
      x += DP[C].se;
      x -= DP.get(A1, C).se + DP.get(A1, C).fi;
      x -= DP.get(B1, C).se + DP.get(B1, C).fi;
      n += DP[C].fi - DP.get(A1, C).fi - DP.get(B1, C).fi;
      ANS += x + n * d / 2;
    }
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}