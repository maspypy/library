#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/suffix_automaton.hpp"

void solve() {
  STR(S);
  Suffix_Automaton<26> X;
  for (auto&& s: S) X.add(s, 'a');
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
