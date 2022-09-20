#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "alg/group_affine.hpp"
#include "graph/link_cut_path.hpp"

using mint = modint998;
using Mono = Group_Affine<mint>;

void solve() {
  LL(N, Q);

  auto f = [&](int v) -> pair<mint, mint> {
    LL(a, b);
    return {mint(a), mint(b)};
  };

  LinkCutTree_Path_Monoid<Mono, 200000> X(N, f);

  FOR(N - 1) {
    LL(u, v);
    X.link(u, v);
  }

  FOR(Q) {
    // X.debug();
    LL(t, a, b, c);
    if (t == 0) {
      LL(d);
      // ab を削除、cd を追加
      X.cut(a, b);
      X.link(c, d);
    }
    if (t == 1) {
      Mono::value_type x = {mint(b), mint(c)};
      X.set(a, x);
    }
    if (t == 2) {
      mint ANS = Mono::eval(X.prod_path(a, b), mint(c));
      print(ANS);
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