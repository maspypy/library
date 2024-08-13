#define PROBLEM "https://judge.yosupo.jp/problem/prefix_substring_lcs"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/prefix_substring_LCS.hpp"

void solve() {
  INT(Q);
  STR(S, T);
  Prefix_Substring_LCS X(S, T);
  FOR(Q) {
    INT(a, b, c);
    print(X.query(a, b, c));
  }
}

signed main() {
  solve();
  return 0;
}
