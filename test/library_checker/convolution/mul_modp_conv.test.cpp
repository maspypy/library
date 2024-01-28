#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/multiplicative_convolution_mod_p.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  INT(P);
  VEC(mint, A, P);
  VEC(mint, B, P);
  A = multiplicative_convolution_mod_p<mint>(P, A, B);
  print(A);
}

signed main() {
  solve();
  return 0;
}
