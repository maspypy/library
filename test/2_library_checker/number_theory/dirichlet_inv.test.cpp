#define PROBLEM \
  "https://judge.yosupo.jp/problem/dirichlet_inverse_and_prefix_sums"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/dirichlet.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Dirichlet DIR(N);
  ll n = DIR.n;
  vc<mint> A(n);
  FOR(i, 1, n) read(A[i]);
  A = DIR.div(DIR.Unit<mint>(), A);
  A.erase(A.begin());
  print(A);
}

signed main() {
  INT(T);
  FOR(T) solve();
}
