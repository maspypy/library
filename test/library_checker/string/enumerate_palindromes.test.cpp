#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/manacher.hpp"

void solve() {
  STR(S);
  auto A = longest_palindrome<1>(S);
  print(A);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
