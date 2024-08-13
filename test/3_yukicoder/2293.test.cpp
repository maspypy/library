#define PROBLEM "https://yukicoder.me/problems/no/2293"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/rollback_weighted_unionfind.hpp"
#include "alg/monoid/xor.hpp"
#include "mod/modint.hpp"

using mint = modint998;
void solve() {
  LL(N, Q);
  Rollback_Weighted_UnionFind<Monoid_Xor<int>> uf(N);

  int init = uf.time();
  int comp = N;

  bool ok = 1;

  FOR(Q) {
    LL(t);
    if (t == 3) {
      uf.rollback(init);
      ok = 1;
      comp = N;
    }
    if (t == 1 || t == 2) {
      t = t - 1;
      LL(u, v);
      --u, --v;
      auto [ru, xu] = uf.get(u);
      auto [rv, xv] = uf.get(v);
      if (ru != rv) {
        uf.merge(u, v, t);
        --comp;
      } else {
        if ((xu ^ t) != xv) ok = 0;
      }
    }
    if (!ok) {
      print(0);
    } else {
      print(mint(2).pow(comp));
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
