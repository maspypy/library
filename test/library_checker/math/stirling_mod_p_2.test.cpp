#define PROBLEM \
  "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/famous/stirling_number_query.hpp"

void solve() {
  LL(T, p);
  Stirling_Number_Query X(p, 0, 1);
  FOR(T) {
    LL(n, k);
    print(X.S2(n, k));
  }
}

signed main() {
  cout << fixed << setprecision(15);

  // LL(T);
  ll T = 1;
  FOR(T) solve();

  return 0;
}
