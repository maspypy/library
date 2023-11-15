#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/lyndon.hpp"

void solve() {
  STR(S);
  Incremental_Lyndon_Factorization<char> LYN;
  for (auto& ch: S) LYN.add(ch);
  print(LYN.factorize());
}

signed main() {
  solve();
  return 0;
}
