#define PROBLEM "https://atcoder.jp/contests/abc280/tasks/abc280_f"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/weighted_unionfind.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, M, Q);
  Weighted_UnionFind<Monoid_Add<ll>> uf(N);
  vi neg(N);

  FOR(M) {
    LL(a, b, c);
    --a, --b;
    auto [ra, xa] = uf[a];
    auto [rb, xb] = uf[b];
    if (ra != rb) {
      uf.merge(a, b, c);
      continue;
    }
    if (xa + c == xb) continue;
    neg[a] = 1;
  }
  FOR(v, N) if (neg[v]) {
    auto [r, x] = uf[v];
    neg[r] = 1;
  }

  FOR(Q) {
    LL(a, b);
    --a, --b;
    auto [ra, xa] = uf[a];
    auto [rb, xb] = uf[b];
    if (ra != rb) {
      print("nan");
    } else {
      if (neg[ra]) {
        print("inf");
      } else {
        print(xb - xa);
      }
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
