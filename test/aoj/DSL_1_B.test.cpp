#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "ds/weightedunionfind.hpp"

void solve() {
  LL(N, Q);
  WeightedUnionFind<Group_Add<ll>> uf(N);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c);
      uf.merge(a, b, c);
    } else {
      LL(a, b);
      auto [ra, xa] = uf.get(a);
      auto [rb, xb] = uf.get(b);
      if (ra != rb)
        print("?");
      else
        print(xb - xa);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
