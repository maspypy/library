#define PROBLEM "https://yukicoder.me/problems/no/981"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/mod_kth_root.hpp"

void solve() {
  LL(p, k, a);
  ll ANS = mod_kth_root_long(k, a, p);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(_, T) solve();

  return 0;
}
