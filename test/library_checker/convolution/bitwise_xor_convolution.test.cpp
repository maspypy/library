#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/xor_convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, 1 << N);
  VEC(mint, B, 1 << N);
  auto C = xor_convolution(A, B);
  print(C);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
