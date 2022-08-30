#include "my_template.hpp"
#include "other/io.hpp"
#include "string/suffix_automation.hpp"

void solve() {
  STR(S);
  Suffix_Automation X;
  for (auto&& s: S) X.add(s);
  print(X.count_substring());
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