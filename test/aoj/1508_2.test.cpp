#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/min.hpp"
#include "ds/bbst/rbst_monoid.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);

  RBST_Monoid<Monoid_Min<int>> ST;
  auto root = ST.new_node(A);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(l, r);
      auto n = ST.erase(root, r);
      ST.insert(root, l, n);
    }
    if (t == 1) {
      LL(l, r);
      ++r;
      print(ST.prod(root, l, r));
    }
    if (t == 2) {
      LL(idx, x);
      ST.set(root, idx, x);
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
