#define PROBLEM "https://yukicoder.me/problems/no/2005"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/sparse_table/disjoint_sparse_table.hpp"
#include "alg/monoid/mul.hpp"
#include "seq/famous/eulerian_number.hpp"

using mint = modint998;

void solve() {
  ll LIM = 5000;
  LL(N, M);
  vvc<mint> A = eulerian_number_2d<mint>(LIM, LIM);

  // M - LIM, ... の積をとりたい
  Disjoint_Sparse_Table<Monoid_Mul<mint>> seg(
      N + LIM + LIM + 100, [&](int i) { return mint(M - LIM + i); });

  auto prod = [&](ll l, ll r) -> mint {
    l -= (M - LIM);
    r -= (M - LIM);
    return seg.prod(l, r);
  };

  vc<mint> dp(LIM + 1);
  FOR(k, 1, LIM + 1) {
    mint& ANS = dp[k];
    ll n = min(k, M);
    FOR(i, n + 1) {
      // N + k + M - i C N + k
      ANS += prod(M - i + 1, N + k + M - i + 1) * A[k][i];
    }
    ANS *= fact_inv<mint>(N + k);
  }
  mint ANS = 0;
  FOR(N) {
    LL(k);
    ANS += dp[k];
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}