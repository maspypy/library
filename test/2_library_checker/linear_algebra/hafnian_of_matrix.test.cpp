#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/hafnian.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VV(mint, B, N, N);
  auto ANS = hafnian(B);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
