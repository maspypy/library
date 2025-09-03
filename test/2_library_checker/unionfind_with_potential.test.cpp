#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/add.hpp"
#include "ds/unionfind/potentialized_unionfind.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  INT(N, Q);
  Potentialized_UnionFind<Monoid_Add<mint>> uf(N);

  FOR(Q) {
    INT(t, u, v);
    if (t == 0) {
      mint x;
      read(x);
      auto [is_same, path] = uf.get_path(v, u);
      bool valid = (!is_same) || (path == x);
      print(valid);
      if (!is_same) uf.merge(v, u, x);
    }
    if (t == 1) {
      auto [is_same, path] = uf.get_path(v, u);
      if (!is_same) {
        print(-1);
      } else {
        print(path);
      }
    }
  }
}

signed main() {
  solve();
  return 0;
}
