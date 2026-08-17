#define PROBLEM "https://yukicoder.me/problems/no/1643"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/is_subsequence.hpp"

void solve() {
  STR(S);
  string ans = "";
  while (is_subsequence(ans, S)) ans += "a";
  print(ans);
}

signed main() {
  solve();

  return 0;
}
