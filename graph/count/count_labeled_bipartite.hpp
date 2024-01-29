#include "poly/fps_log.hpp"
#include "poly/fps_sqrt.hpp"
#include "ds/power_query.hpp"

// connected = false: https://oeis.org/A047864
// connected = true: https://oeis.org/A001832
template <typename mint>
vc<mint> count_labeled_bipartite(int N, bool connected) {
  // colored bipartite
  vc<mint> F(N + 1);
  mint ipow = 1;
  F[0] = 1;
  FOR(i, 1, N + 1) F[i] = F[i - 1] * ipow, ipow *= inv<mint>(2);
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  F = convolution(F, F);
  F.resize(N + 1);
  mint pow = 1, c = 1;
  FOR(i, N + 1) F[i] *= c, c *= pow, pow += pow;

  if (connected) {
    F = fps_log(F);
    FOR(i, N + 1) F[i] *= inv<mint>(2);
    FOR(i, N + 1) F[i] *= fact<mint>(i);
    return F;
  }
  F = fps_sqrt(F);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  return F;
}