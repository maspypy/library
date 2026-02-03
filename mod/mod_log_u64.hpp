#include "mod/mod_inv_u64.hpp"

// https://contest.ucup.ac/contest/2693/problem/15032
pair<u64, u64> mod_log_u64_primitive_root(u64 a) {
  assert(a & 1);
  u64 sgn = 0;
  if (a & 2) sgn = 1, a = -a;
  // X=5^K mod 2^n
  ll n = 2;
  u64 K = 0;
  u64 X = 1;
  u64 Y = 5;  // pow(5,2^{n-2})
  FOR(62) {
    if ((X - a) >> n & 1) {
      K += u64(1) << (n - 2);
      X *= Y;
    }
    Y *= Y;
    ++n;
  }
  return {sgn, K};
}

// find smallest n such that a^n=b or return -1
ll mod_log_u64(u64 a, u64 b) {
  if (a % 2 == 0) {
    u64 x = 1;
    FOR(n, 65) {
      if (x == b) return n;
      x *= a;
    }
  }
  if (a * b % 2 == 0) return -1;

  auto [X1, Y1] = mod_log_u64_primitive_root(a);
  auto [X2, Y2] = mod_log_u64_primitive_root(b);
  /*
  X1 * n = X2 mod 2
  Y1 * n = Y2 mod 2^{62}
  */
  u64 mod = u64(1) << 62;
  ll k = lowbit(Y1);
  k = (k == -1 ? 62 : k);
  if (Y2 & ((u64(1) << k) - 1)) return -1;
  Y1 >>= k;
  Y2 >>= k;
  mod >>= k;
  u64 n = (mod == 1 ? 0 : mod_inv_u64(Y1) * Y2 % mod);

  FOR(2) {
    if (X1 * n % 2 == X2) return n;
    n += mod;
  }
  return -1;
}
