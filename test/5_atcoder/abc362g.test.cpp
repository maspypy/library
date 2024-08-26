#define PROBLEM "https://atcoder.jp/contests/abc362/tasks/abc362_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/add.hpp"
#include "string/trie.hpp"

void solve() {
  STR(S);
  INT(Q);

  Trie<26> trie;
  FOR(Q) {
    STR(t);
    trie.add(t, 'a');
  }

  trie.calc_suffix_link(1);

  ll n = trie.n_node;
  vc<int> dp(n);
  int v = 0;

  for (auto &ch: S) {
    v = trie.TO[v][ch - 'a'];
    dp[v]++;
  }

  vc<int> V = trie.BFS;
  reverse(all(V));
  for (auto &v: V) {
    int p = trie.suffix_link[v];
    if (p != -1) dp[p] += dp[v];
  }

  FOR(q, Q) {
    int v = trie.words[q];
    print(dp[v]);
  }
}

int main() {
  solve();
  return 0;
}
