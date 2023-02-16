#define PROBLEM "https://atcoder.jp/contests/abc268/tasks/abc268_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/trie.hpp"

void solve() {
  STR(S);
  LL(N);
  Trie<26> X;
  FOR(N) {
    STR(T);
    X.add(T, 'a');
  }
  X.calc_suffix_link(1);
  auto CNT = X.calc_count();

  ll ANS = 0;
  int v = 0;
  for (auto&& x: S) {
    v = X.TO[v][x - 'a'];
    if (CNT[v]) {
      ++ANS;
      v = 0;
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
