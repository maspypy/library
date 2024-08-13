#define PROBLEM "https://yukicoder.me/problems/no/1077"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/slope.hpp"

void solve() {
  LL(N);
  Slope_Trick X;
  FOR(N) {
    LL(x);
    X.add_abs(x);
    X.clear_right();
  }

  auto [lx, rx, min_f] = X.get_min();
  print(min_f);
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
