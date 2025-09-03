#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/longest_common_substring.hpp"

void solve() {
  STR(A, B);
  print(longest_common_substring(A, B));
}

signed main() {
  solve();
  return 0;
}