
#include "mod/min_of_linear_segments.hpp"

// min_{x in [L, R)} (ax+b mod)
pair<ll, int> min_of_linear(ll L, ll R, int a, int b, int mod) {
  ll n = R - L;
  b = (b + a * L) % mod;
  if (b < 0) b += mod;
  auto [X, DX] = min_of_linear_segments(a, b, mod);
  int x = 0;
  FOR(i, len(X) - 1) {
    int xl = X[i], xr = X[i + 1];
    if (xr < n) {
      x = xr;
      continue;
    }
    x = xl + (n - x) / DX[i] * DX[i];
    break;
  }
  int y = (ll(a) * x + b) % mod;
  return {L + x, y};
}