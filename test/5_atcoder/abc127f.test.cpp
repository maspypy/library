#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope.hpp"

void solve() {
  LL(Q);
  Slope_Trick f;
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(a, b);
      f.add_const(b);
      f.add_abs(a);
    }
    if (t == 2) {
      auto [xl, xr, min_f] = f.get_min();
      print(xl, min_f);
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
