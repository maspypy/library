#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwickraq.hpp"

void solve() {
  LL(N, Q);
  FenwickRAQ<Monoid_Add<ll>> bit(N);
  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(L, R, x);
      bit.add(--L, R, x);
    } else {
      LL(L);
      print(bit.prod(L - 1, L));
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
