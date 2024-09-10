#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/weighted_unionfind.hpp"
#include "alg/monoid/add.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  Weighted_UnionFind<Monoid_Add<mint>> uf(N);

  FOR(Q) {
    INT(t);
    if (t == 0) { INT(u, v, x); }
  }
}

signed main() {
  solve();
  return 0;
}
