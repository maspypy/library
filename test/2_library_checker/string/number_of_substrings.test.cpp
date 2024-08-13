#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffix_array.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  Suffix_Array sa(S);
  ll ANS = N * (N + 1) / 2;
  ANS -= SUM<ll>(sa.LCP);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
