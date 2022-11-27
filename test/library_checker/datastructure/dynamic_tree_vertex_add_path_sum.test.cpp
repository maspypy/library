#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/add.hpp"
#include "graph/ds/link_cut_path.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);

  LinkCutTree_Path<Monoid_Add<ll>, 200000> X(A);

  FOR(N - 1) {
    LL(u, v);
    X.link(u, v);
  }

  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c, d);
      X.cut(a, b);
      X.link(c, d);
    }
    if (t == 1) {
      LL(p, x);
      X.multiply(p, x);
    }
    if (t == 2) {
      LL(a, b);
      print(X.prod_path(a, b));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}