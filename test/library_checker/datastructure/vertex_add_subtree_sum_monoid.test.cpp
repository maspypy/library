#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/treemonoid.hpp"
#include "alg/group_add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph<int, 1> G(N);
  FOR3(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  G.build();

  HLD hld(G);
  using Mono = Group_Add<ll>;

  TreeMonoid<decltype(hld), Mono, false> TM(hld, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      A[v] += x;
      TM.set(v, A[v]);
    } else {
      LL(u);
      print(TM.prod_subtree(u));
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
