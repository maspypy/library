#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/online_convolution.hpp"
using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, f, N);
  VEC(mint, g, M);
  f.resize(N + M - 1);
  g.resize(N + M - 1);
  vc<mint> h(N + M - 1);

  Online_Convolution<mint> OC;
  FOR(i, N + M - 1) { h[i] = OC.query(i, f[i], g[i]); }
  print(h);
}

signed main() {
  solve();

  return 0;
}
