#include "nt/factor.hpp"
vc<ll> divisors(ll N) {
  auto pf = factor(N);
  vi div = {1};
  for (auto&& [p, e]: pf) {
    ll n = len(div);
    ll pp = 1;
    FOR3(i, 1, e + 1) {
      pp *= p;
      FOR(j, n) div.eb(div[j] * pp);
    }
  }
  return div;
}