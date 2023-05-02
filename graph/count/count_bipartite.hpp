#include "poly/fps_log.hpp"
#include "poly/fps_sqrt.hpp"
#include "ds/power_query.hpp"

// connected = false: https://oeis.org/A047864
// connected = true: https://oeis.org/A001832
template <typename mint>
vc<mint> count_bipartite(int N, bool connected) {
  Power_Query<Monoid_Mul<mint>> POW2(mint(2));
  Power_Query<Monoid_Mul<mint>> iPOW2(inv<mint>(2));

  // colored bipartite
  vc<mint> F(N + 1);
  FOR(i, N + 1) F[i] = fact_inv<mint>(i) * iPOW2[i * (i - 1) / 2];
  F = convolution(F, F);
  F.resize(N + 1);
  FOR(i, N + 1) F[i] *= POW2[i * (i - 1) / 2];

  // colored bipartite connected
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