#define PROBLEM "https://yukicoder.me/problems/no/502"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/factorial107.hpp"

void solve() {
  LL(N);
  print(factorial107(N));
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
