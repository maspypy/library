#include "random/base.hpp"
#include "mod/mod_pow.hpp"

// p は素数. 解なしは -1.
int mod_sqrt(int a, int p) {
  if (p == 2) return a;
  if (a == 0) return 0;
  int k = (p - 1) / 2;
  if (mod_pow(a, k, p) != 1) return -1;
  auto find = [&]() -> pi {
    while (1) {
      ll b = RNG(2, p);
      ll D = (b * b - a) % p;
      if (D == 0) return {b, D};
      if (mod_pow(D, k, p) != 1) return {b, D};
    }
  };
  auto [b, D] = find();
  if (D == 0) return b;
  ++k;
  // (b + sqrt(D))^k
  ll f0 = b, f1 = 1, g0 = 1, g1 = 0;
  while (k) {
    if (k & 1) {
      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);
      g0 %= p, g1 %= p;
    }
    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);
    f0 %= p, f1 %= p;
    k >>= 1;
  }
  if (g0 < 0) g0 += p;
  return g0;
}

// p は素数. 解なしは -1.
ll mod_sqrt_64(ll a, ll p) {
  if (p == 2) return a;
  if (a == 0) return 0;
  ll k = (p - 1) / 2;
  if (mod_pow_64(a, k, p) != 1) return -1;
  auto find = [&]() -> pair<i128, i128> {
    while (1) {
      i128 b = RNG(2, p);
      i128 D = b * b - a;
      if (D == 0) return {b, D};
      if (mod_pow_64(D, k, p) != 1) return {b, D};
    }
  };
  auto [b, D] = find();
  if (D == 0) return b;
  ++k;
  // (b + sqrt(D))^k
  i128 f0 = b, f1 = 1, g0 = 1, g1 = 0;
  while (k) {
    if (k & 1) {
      tie(g0, g1) = mp(f0 * g0 + D * f1 % p * g1, f1 * g0 + f0 * g1);
      g0 %= p, g1 %= p;
    }
    tie(f0, f1) = mp(f0 * f0 + D * f1 % p * f1, 2 * f0 * f1);
    f0 %= p, f1 %= p;
    k >>= 1;
  }
  return g0;
}
