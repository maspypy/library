#include "nt/factor.hpp"

// sort はしない
vc<ll> divisors_by_pf(const vc<pair<ll, int>>& pf) {
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

// sort はしない
vc<ll> divisors(ll N) {
  auto pf = factor(N);
  return divisors_by_pf(pf);
}

// sort はしない
vc<ll> divisors_by_spf(ll N, vc<int>& spf) {
  auto pf = factor_by_spf(N, spf);
  return divisors_by_pf(pf);
}