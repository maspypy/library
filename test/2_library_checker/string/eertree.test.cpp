#define PROBLEM "https://judge.yosupo.jp/problem/eertree"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/palindromic_tree.hpp"

void solve() {
  STR(S);
  Palindromic_Tree<26> X(S, 'a');
  int n = len(X.nodes);
  vc<int> par(n, -1);
  FOR(i, n) {
    for (auto& j: X.nodes[i].TO) {
      if (j != -1) par[j] = i;
    }
  }
  print(n - 2);
  FOR(i, 2, n) { print(par[i] - 1, X.nodes[i].link - 1); }
  vc<int> ANS = {X.path.begin() + 1, X.path.end()};
  for (auto& x: ANS) --x;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
