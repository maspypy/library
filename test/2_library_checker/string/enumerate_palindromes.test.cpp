#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/manacher.hpp"

void solve() {
  STR(S);
  auto LR = manacher(S);
  vc<int> ANS(len(S) * 2 - 1);
  for (auto&& [l, r]: LR) { ANS[l + r - 1] = r - l; }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
