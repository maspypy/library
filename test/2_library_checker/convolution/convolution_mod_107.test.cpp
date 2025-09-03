#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
using mint = modint107;

void solve() {
  LL(N, M);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto ANS = convolution(A, B);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
