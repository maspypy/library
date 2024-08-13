#define PROBLEM "https://judge.yosupo.jp/problem/palindromes_in_deque"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/double_ended_palindromic_tree.hpp"

void solve() {
  INT(Q);
  Double_Ended_Palindromic_Tree<26, 'a'> tree(Q);
  FOR(q, Q) {
    INT(t);
    if (t == 0) {
      CHAR(c);
      tree.push_front(c);
    }
    if (t == 1) {
      CHAR(c);
      tree.push_back(c);
    }
    if (t == 2) { tree.pop_front(); }
    if (t == 3) { tree.pop_back(); }
    int a = tree.count_distinct_palindrome();
    int b = tree.maximum_prefix_palindrome();
    int c = tree.maximum_suffix_palindrome();
    print(a, b, c);
  }
}

signed main() { solve(); }