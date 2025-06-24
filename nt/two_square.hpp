#include "nt/gaussian_integers.hpp"

vc<pair<ll, ll>> two_square(ll N, bool only_nonnegative) {
  vc<pi> ANS;
  if (N == 0) {
    ANS.eb(0, 0);
    return ANS;
  }
  if (only_nonnegative) {
    for (auto& g: solve_norm_equation<i128>(N)) { ANS.eb(g.x, g.y); }
    ll sqN = sqrtl(N);
    if (sqN * sqN == N) ANS.eb(0, sqN);
    return ANS;
  }
  for (auto& g: solve_norm_equation<i128>(N)) {
    FOR(4) {
      ANS.eb(g.x, g.y);
      tie(g.x, g.y) = mp(-g.y, g.x);
    }
  }
  return ANS;
}
