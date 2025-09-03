#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/range_add_range_sum.hpp"

void solve() {
  LL(N, Q);
  Range_Add_Range_Sum<Monoid_Add<ll>> bit(N);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(L, R, x);
      bit.add(--L, R, x);
    } else {
      LL(L);
      print(bit.sum(L - 1, L));
    }
  }
}

signed main() {
  solve();

  return 0;
}
