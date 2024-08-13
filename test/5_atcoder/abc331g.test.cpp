#define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/product_of_one_minus_xn.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N, M);
  VEC(ll, A, M);
  poly f = product_of_one_minus_xn<mint, ll>(A, N);

  mint ANS = 0;
  FOR(S, N + 1) {
    if (S == N) continue;
    ANS -= f[S] * inv<mint>(N - S);
  }
  ANS *= mint(N);
  if (M % 2 == 1) ANS = -ANS;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}