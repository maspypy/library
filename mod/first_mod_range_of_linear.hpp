#include "mod/min_of_linear_segments.hpp"

// ax+b in {L, ..., R-1} mod となる最小の x>=0 を返す
// 例えば ax+b=1 なら ax+b in {-1} mod 2 のようにする
// 存在しなければ -1
// L<0 や mod<=R も ok
int first_mod_range_of_linear(ll L, ll R, ll a, ll b, int mod) {
  assert(L <= R);
  b -= L, R -= L;
  if (R >= mod) return 0;
  a = bmod<ll>(a, mod), b = bmod<ll>(b, mod);
  // ax+b<R
  if (b < R) return 0;
  auto [X, DX] = min_of_linear_segments(a, b, mod);
  FOR(i, len(DX)) {
    ll x1 = X[i], x2 = X[i + 1];
    ll y2 = (a * x2 + b) % mod;
    if (y2 >= R) continue;
    ll y1 = (a * x1 + b) % mod;
    ll d = (y1 - y2) * DX[i] / (x2 - x1);
    ll k = floor(y1 - R, d) + 1;
    return x1 + k * DX[i];
  }
  return -1;
}