#define PROBLEM "https://yukicoder.me/problems/no/2243"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/implicit_matrix/pascal.hpp"
#include "poly/convolution_all.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(M, N);
  // M つかわない

  VEC(int, A, N);
  map<int, int> MP;
  for (auto&& x: A) MP[x]++;
  A.clear();
  for (auto&& [a, b]: MP) A.eb(b);

  // binom(x,a) の総積を求める
  vvc<mint> polys;
  for (auto&& a: A) {
    FOR(i, a) { polys.eb(vc<mint>({-i, 1})); }
  }
  vc<mint> F = convolution_all(polys);
  vc<mint> X(N + 1);
  FOR(i, N + 1) X[i] = i;
  F = multipoint_eval(F, X);

  /*
  FOR(n, N + 1) {
    F[n] = 1;
    for (auto&& a: A) { F[n] *= C<mint>(n, a) * fact<mint>(a); }
  }
  */
  F = pascal<mint>(F, 0, 1);
  print(SUM<mint>(F));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
