#include "nt/factor.hpp"
#include "random/base.hpp"
#include "mod/mod_sqrt.hpp"
#include "mod/dynamic_modint.hpp"

// N = a^2+b^2+c^2+d^2 となる (a,b,c,d) をひとつ返す
tuple<ll, ll, ll, ll> four_square(ll N) {
  if (N == 0) return {0, 0, 0, 0};
  using T4 = tuple<ll, ll, ll, ll>;
  auto mul = [&](T4 x, T4 y) -> T4 {
    auto [x1, x2, x3, x4] = x;
    auto [y1, y2, y3, y4] = y;
    ll z1 = abs(x1 * y1 + x2 * y2 + x3 * y3 + x4 * y4);
    ll z2 = abs(x1 * y2 - x2 * y1 + x3 * y4 - x4 * y3);
    ll z3 = abs(x1 * y3 - x2 * y4 - x3 * y1 + x4 * y2);
    ll z4 = abs(x1 * y4 + x2 * y3 - x3 * y2 - x4 * y1);
    return {z1, z2, z3, z4};
  };

  auto solve_p = [&](ll p) -> T4 {
    if (p == 2) return {1, 1, 0, 0};
    using mint = dmint;
    mint::set_mod(p);
    auto [a, b] = [&]() -> pair<ll, ll> {
      while (1) {
        ll a = RNG(0, p);
        ll bb = (p - 1 - a * a) % p;
        if (bb < 0) bb += p;
        ll b = mod_sqrt<mint>(bb).val;
        if ((a * a + b * b + 1) % p == 0) return {a, b};
      }
      return {0, 0};
    }();
    T4 x = {a, b, 1, 0};
    while (1) {
      auto& [x1, x2, x3, x4] = x;
      chmin(x1, p - x1), chmin(x2, p - x2), chmin(x3, p - x3),
          chmin(x4, p - x4);
      ll m = (x1 * x1 + x2 * x2 + x3 * x3 + x4 * x4) / p;
      if (m == 1) break;
      ll y1 = x1 % m, y2 = x2 % m, y3 = x3 % m, y4 = x4 % m;
      if (y1 > m / 2) y1 -= m;
      if (y2 > m / 2) y2 -= m;
      if (y3 > m / 2) y3 -= m;
      if (y4 > m / 2) y4 -= m;
      auto [z1, z2, z3, z4] = mul(x, {y1, y2, y3, y4});
      x = mt(z1 / m, z2 / m, z3 / m, z4 / m);
    }
    return x;
  };
  T4 x = {1, 0, 0, 0};
  for (auto&& [p, e]: factor(N)) { FOR(e) x = mul(x, solve_p(p)); }
  return x;
}
