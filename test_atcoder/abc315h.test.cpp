#define PROBLEM "https://atcoder.jp/contests/abc315/tasks/abc315_h"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/online/online_convolution.hpp"
#include "mod/modint.hpp"
#include "poly/ntt.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Online_Convolution<mint> X;
  VEC(mint, A, N);
  A.insert(A.begin(), mint(0));

  // F^2
  mint sm = 0;
  mint f = 1;
  vc<mint> ANS(N);

  FOR(i, 1, N + 1) {
    mint v = X.query(i - 1, f, f);
    sm += v;
    f = sm * A[i];
    ANS[i - 1] = f;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
