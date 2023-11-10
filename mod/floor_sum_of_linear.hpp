#pragma once

// sum_{x in [L,R)} floor(ax + b, mod)
// I は範囲内で ax+b がオーバーフローしない程度
template <typename O = i128, typename I = long long>
O floor_sum_of_linear(I L, I R, I a, I b, I mod) {
  assert(L <= R);
  O res = 0;
  b += L * a;
  I N = R - L;

  if (b < 0) {
    I k = ceil(-b, mod);
    b += k * mod;
    res -= O(N) * O(k);
  }

  while (N) {
    I q;
    tie(q, a) = divmod(a, mod);
    res += (N & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));
    if (b >= mod) {
      tie(q, b) = divmod(b, mod);
      res += O(N) * q;
    }
    tie(N, b) = divmod(a * N + b, mod);
    tie(a, mod) = mp(mod, a);
  }
  return res;
}