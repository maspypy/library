#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/lcm_convolution.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VEC(mint, A, N);
  VEC(mint, B, N);
  A.insert(A.begin(), 0);
  B.insert(B.begin(), 0);
  A = lcm_convolution(A, B);
  A.erase(A.begin());
  print(A);
}

signed main() {
  solve();

  return 0;
}
