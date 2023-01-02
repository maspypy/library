#include "nt/factor.hpp"

template <bool SORT>
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
  if (SORT) sort(all(div));
  return div;
}

template <bool SORT>
vc<ll> divisors(ll N) {
  auto pf = factor(N);
  return divisors_by_pf<SORT>(pf);
}

template <bool SORT>
vc<ll> divisors_by_lpf(ll N, vc<int>& lpf) {
  auto pf = factor_by_lpf(N, lpf);
  return divisors_by_pf<SORT>(pf);
}