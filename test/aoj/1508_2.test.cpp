#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/min.hpp"
#include "ds/bbst/rbst_monoid.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);

  RBST_Monoid<Monoid_Min<int>, 200000> X;
  auto root = X.new_node(A);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(l, r);
      auto [nl, nm, nr] = X.split3(root, l, r + 1);
      auto [a, b] = X.split(nm, (nm->size) - 1);
      nm = X.merge(b, a);
      root = X.merge3(nl, nm, nr);
    }
    if (t == 1) {
      LL(l, r);
      print(X.prod(root, l, ++r));
    }
    if (t == 2) {
      LL(idx, x);
      X.set(root, idx, x);
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