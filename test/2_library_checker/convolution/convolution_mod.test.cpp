#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
using mint = modint998;

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
