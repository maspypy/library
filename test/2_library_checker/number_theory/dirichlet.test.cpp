#define PROBLEM \
  "https://judge.yosupo.jp/problem/dirichlet_convolution_and_prefix_sums"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/dirichlet.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Dirichlet DIR(N);
  ll n = DIR.n;
  vc<mint> A(n), B(n);
  FOR(i, 1, n) read(A[i]);
  FOR(i, 1, n) read(B[i]);
  A = DIR.convolution(A, B);
  A.erase(A.begin());
  print(A);
}

signed main() {
  INT(T);
  FOR(T) solve();
}
