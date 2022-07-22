#pragma once

// sum_{x in [L,R)} floor(ax + b, mod)
i128 floor_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {
  assert(L <= R);
  i128 res = 0;
  b += L * a;
  ll N = R - L;
  while (N) {
    ll q;
    tie(q, a) = divmod(a, mod);
    res += i128(N) * (N - 1) / 2 * q;
    tie(q, b) = divmod(b, mod);
    res += i128(N) * q;
    tie(N, b) = divmod(a * N + b, mod);
    tie(a, mod) = mp(mod, a);
  }
  return res;
}
