#define PROBLEM "https://yukicoder.me/problems/no/1643"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/is_subseq.hpp"

void solve() {
  STR(S);
  string ans = "";
  while (is_subseq(ans, S)) ans += "a";
  print(ans);
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
