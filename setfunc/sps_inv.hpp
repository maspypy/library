#include "setfunc/ranked_zeta.hpp"

template <typename mint, int LIM>
vc<mint> sps_inv(vc<mint>& dp) {
  const int N = topbit(len(dp));
  assert(len(dp) == (1 << N) && dp[0] == mint(1));
  auto RA = ranked_zeta<mint, LIM>(dp);
  array<mint, LIM + 1> g;
  FOR(s, 1 << N) {
    auto& f = RA[s];
    g[0] = 1;
    FOR(k, 1, N + 1) {
      g[k] = 0;
      FOR(i, k) g[k] -= g[i] * f[k - i];
    }
    RA[s] = g;
  }
  return ranked_mobius<mint, LIM>(RA);
}
