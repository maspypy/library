#define PROBLEM "https://yukicoder.me/problems/no/2305"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "graph/base.hpp"

#include "seq/find_linear_rec.hpp"
#include "poly/coef_of_rational_fps.hpp"

using mint = modint998;

void solve() {
  LL(N);
  ++N;
  vc<int> par(N, -1);
  vc<mint> W(N, -1);
  FOR(i, 1, N) { read(par[i]); }
  FOR(i, 1, N) read(W[i]);

  Graph<mint, 0> G(N);
  FOR(i, 1, N) { G.add(par[i], i, W[i]); }
  G.build();
  // sparse matrix
  using T = tuple<int, int, mint>;
  vc<T> dat;
  FOR(v, N) {
    vc<int> TO;
    vc<mint> WT;
    for (auto&& e: G[v]) {
      if (e.to == par[v]) continue;
      TO.eb(e.to), WT.eb(e.cost);
    }
    if (!TO.empty()) {
      mint cf = SUM<mint>(WT);
      cf = mint(1) / cf;
      FOR(i, len(TO)) dat.eb(v, TO[i], WT[i] * cf);
    } else {
      dat.eb(v, 0, 1);
    }
  }

  auto apply = [&](vc<mint> X) -> vc<mint> {
    vc<mint> Y(N);
    for (auto&& [a, b, c]: dat) Y[b] += X[a] * c;
    return Y;
  };

  int L = N + N + 10;
  vv(mint, dp, L, N);
  dp[0][0] = mint(1);
  FOR(i, L - 1) dp[i + 1] = apply(dp[i]);
  FOR(i, L - 1) FOR(j, N) dp[i + 1][j] += dp[i][j];

  vc<mint> wt(N);
  FOR(i, N) wt[i] = RNG(0, mint::get_mod() - 1);
  vc<mint> S(L);
  FOR(i, L) FOR(j, N) S[i] += dp[i][j] * wt[j];

  using poly = vc<mint>;
  poly f = find_linear_rec(S);
  ll n = len(f);

  LL(Q);
  FOR(Q) {
    LL(v, K);

    vc<mint> A(n - 1);
    FOR(i, n - 1) A[i] = dp[i][v];

    // 数列 A, 漸化式 f を補間
    poly g = convolution(A, f);
    g.resize(n - 1);
    mint ANS = coef_of_rational_fps(g, f, K);

    if (v == 0) ANS -= mint(1);
    print(ANS);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
