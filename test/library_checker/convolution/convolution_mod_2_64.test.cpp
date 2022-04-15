#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution_mod_2_64.hpp"

void solve() {
  LL(N, M);
  VEC(u64, A, N);
  VEC(u64, B, M);
  auto C = convolution_mod_2_64(A, B);
  print(C);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
