#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/binary_trie/binarytrie.hpp"

void solve() {
  LL(Q);
  BinaryTrie<30> trie;
  FOR(Q) {
    LL(t, x);
    if (t == 0 && trie.count(x) == 0) trie.add(x, 1);
    if (t == 1 && trie.count(x) == 1) trie.add(x, -1);
    if (t == 2) { print(trie.min(x)); }
  }
}

signed main() {
  solve();

  return 0;
}
