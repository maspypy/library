#define PROBLEM "https://yukicoder.me/problems/no/2747"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/sum_of_powers.hpp"
#include "poly/lagrange_interpolate_iota.hpp"
#include "mod/factorial998.hpp"

using mint = modint998;

void solve() {
  LL(N, K);

  vc<mint> F(K + 10);
  FOR(d, 1, K + 10) {
    F[d] += mint(N * N - N) * mint(d).pow(K);
    F[d] -= mint(N - 1) * mint(d).pow(K + 1);
  }
  F = cumsum<mint>(F);

  mint ans = lagrange_interpolate_iota<mint>(F, N);
  mint ANS = mint(2) * factorial998(N - 2) * ans;
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
