#include "nt/factor.hpp"

vc<ll> divisors_by_pf(const vc<pair<ll, int>>& pf, bool SORT) {
  vi div = {1};
  for (auto&& [p, e]: pf) {
    ll n = len(div);
    ll pp = 1;
    FOR3(i, 1, e + 1) {
      pp *= p;
      FOR(j, n) div.eb(div[j] * pp);
    }
  }
  if (SORT) sort(all(div));
  return div;
}

vc<ll> divisors(ll N, bool SORT) {
  auto pf = factor(N);
  return divisors_by_pf(pf, SORT);
}

vc<ll> divisors_by_lpf(ll N, vc<int>& lpf, bool SORT) {
  auto pf = factor_by_lpf(N, lpf);
  return divisors_by_pf(pf, SORT);
}