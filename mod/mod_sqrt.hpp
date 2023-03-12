#include "random/base.hpp"

template <typename mint>
mint mod_sqrt(mint a) {
  int p = mint::get_mod();
  if (p == 2) return a;
  if (a == 0) return 0;
  int k = (p - 1) / 2;
  if (a.pow(k) != 1) return 0;
  auto find = [&]() -> pair<mint, mint> {
    while (1) {
      mint b = RNG(2, p);
      mint D = b * b - a;
      if (D == 0) return {b, D};
      if (D.pow(k) != mint(1)) return {b, D};
    }
  };
  auto [b, D] = find();
  if (D == 0) return b;
  ++k;
  // (b + sqrt(D))^k
  mint f0 = b, f1 = 1;
  mint g0 = 1, g1 = 0;
  while (k) {
    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1 * g1, f1 * g0 + f0 * g1); }
    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2) * f0 * f1);
    k >>= 1;
  }
  return g0;
}
