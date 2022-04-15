#pragma once
#include "nt/primetable.hpp"

// a^0, ..., a^{N-1}
template <typename mint>
vc<mint> powertable_1(mint a, ll N) {
  // table of a^i
  vc<mint> f(N, 1);
  FOR(i, N - 1) f[i + 1] = a * f[i];
  return f;
}

// 0^e, ..., (N-1)^e
template <typename mint>
vc<mint> powertable_2(ll e, ll N) {
  auto primes = primetable(N);
  vc<mint> f(N, 1);
  f[0] = mint(0).pow(e);
  for (auto&& p: primes) {
    if (p > N) break;
    mint xp = mint(p).pow(e);
    ll pp = p;
    while (pp < N) {
      ll i = pp;
      while (i < N) {
        f[i] *= xp;
        i += pp;
      }
      pp *= p;
    }
  }
  return f;
}
