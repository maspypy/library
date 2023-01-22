#define PROBLEM "https://atcoder.jp/contests/abc200/tasks/abc200_a"

#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  print(ceil(N, 100));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
