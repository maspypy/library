#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/suffix_automaton.hpp"

void solve() {
  STR(S);
  Suffix_Automaton<26> X(S, 'a');
  int n = X.n_node;
  ll ANS = 0;
  FOR(i, 1, n) {
    auto [a, b] = X.len_range(i);
    ANS += b - a;
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
