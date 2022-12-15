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
    auto dat = X.collect_dist(v);
    FOR(n, len(dat)) {
      vc<mint> F;
      for (auto&& [v, dv]: dat[n]) {
        if (dv >= len(F)) F.resize(dv + 1);
        F[dv] += A[v];
      }
      int s = len(F);
      reverse(all(F));
      vc<mint> F1(s + s);
      FOR(i, len(F1)) F1[i] = inv<mint>(i + 1) * inv<mint>(i + 1);
      F = convolution(F, F1);
      F = {F.begin() + s - 1, F.end()};
      if (n > 0) {
        for (auto&& x: F) x = -x;
      }
      for (auto&& [v, dv]: dat[n]) { ANS[v] += F[dv]; }
    }
  }

  mint k0 = fact<mint>(N);
  k0 *= k0;
  for (auto&& x: ANS) x *= k0;
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
