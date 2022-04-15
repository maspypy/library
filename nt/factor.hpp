#pragma once
#include "nt/primetest.hpp"

mt19937_64 rng_mt{random_device{}()};
ll rnd(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }

ll rho(ll n, ll c) {
  m64::set_mod(n);
  assert(n > 1);
  const m64 cc(c);
  auto f = [&](m64 x) { return x * x + cc; };
  m64 x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (__lg(n) / 5); // ?
  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(_, r) y = f(y);
    for (ll k = 0; k < r and g == 1; k += m) {
      z = y;
      FOR(_, min(m, r - k)) y = f(y), q *= x - y;
      g = gcd(q.val(), n);
    }
  }
  if (g == n)
    do {
      z = f(z);
      g = gcd((x - z).val(), n);
    } while (g == 1);
  return g;
}

ll find_prime_factor(ll n) {
  assert(n > 1);
  if (primetest(n))
    return n;
  FOR(_, 100) {
    ll m = rho(n, rnd(n));
    if (primetest(m))
      return m;
    n = m;
  }
  cerr << "failed" << endl;
  assert(false);
  return -1;
}

vc<pi> factor(ll n) {
  assert(n >= 1);
  vc<pi> pf;
  FOR3(p, 2, 100) {
    if (p * p > n)
      break;
    if (n % p == 0) {
      ll e = 0;
      do {
        n /= p, e += 1;
      } while (n % p == 0);
      pf.eb(p, e);
    }
  }
  while (n > 1) {
    ll p = find_prime_factor(n);
    ll e = 0;
    do {
      n /= p, e += 1;
    } while (n % p == 0);
    pf.eb(p, e);
  }
  sort(all(pf));
  return pf;
}
