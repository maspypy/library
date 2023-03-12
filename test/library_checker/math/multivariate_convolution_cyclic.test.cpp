#define PROBLEM \
  "https://judge.yosupo.jp/problem/multivariate_convolution_cyclic"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/multivar_convolution_cyclic.hpp"
#include "mod/modint.hpp"

using mint = dmint;

void solve() {
  INT(p, K);
  mint::set_mod(p);
  VEC(int, ns, K);
  int N = 1;
  for (auto&& n: ns) N *= n;
  VEC(mint, f, N);
  VEC(mint, g, N);
  print(multivar_convolution_cyclic(ns, f, g));
}

signed main() {
  solve();
  return 0;
}