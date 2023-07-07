#define PROBLEM "https://yukicoder.me/problems/no/1796"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "mod/modint.hpp"
#include "graph/centroid.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, N);
  Graph<int, 0> G(N);
  G.read_tree();
  vc<mint> ANS(N);

  Centroid_Decomposition<decltype(G)> X(G);
  FOR(v, N) {
    auto [V, dp, indptr] = X.collect_dist(v);
    auto calc = [&](vc<int> V, vc<int> dp, int sgn) -> void {
      vc<mint> F;
      int n = len(V);
      FOR(i, n) {
        int v = V[i], dv = dp[i];
        if (dv >= len(F)) F.resize(dv + 1);
        F[dv] += A[v];
      }
      int s = len(F);
      reverse(all(F));
      vc<mint> F1(s + s);
      FOR(i, len(F1)) F1[i] = inv<mint>(i + 1) * inv<mint>(i + 1);
      F = convolution(F, F1);
      F = {F.begin() + s - 1, F.end()};
      if (sgn == -1) {
        for (auto&& x: F) x = -x;
      }
      FOR(i, n) {
        int v = V[i], dv = dp[i];
        ANS[v] += F[dv];
      }
    };
    calc(V, dp, 1);
    FOR(i, 1, len(indptr) - 1) {
      int l = indptr[i], r = indptr[i + 1];
      calc({V.begin() + l, V.begin() + r}, {dp.begin() + l, dp.begin() + r},
           -1);
    }
  }

  mint k0 = fact<mint>(N);
  k0 *= k0;
  for (auto&& x: ANS) x *= k0;
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}
