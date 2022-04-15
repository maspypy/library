#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "mod/modint.hpp"
using mint = amint;

void solve() {
  LL(N, M);
  mint::set_mod(1'000'000'007);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto ANS = convolution(A, B);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
