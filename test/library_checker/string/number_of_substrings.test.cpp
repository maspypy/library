#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffixarray.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  SuffixArray sa(S);
  ll ANS = N * (N + 1) / 2;
  ANS -= SUM(sa.LCP);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
