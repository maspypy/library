#include "mod/modint.hpp"
#include "mod/mod_inv.hpp"

namespace DISCRETE_LOG_998 {
const int A = 32768;
const int B = 30464;
const int r = 3;
const int mod = 998244353;

u32 rpow_0[A + 1];
u32 rpow_1[A + 1];
u32 AX[4 * B + 1];
u32 AI[4 * B + 1];
u32 BX[4 * B + 1];
u32 BI[4 * B + 1];

u32 get_pow_30(u32 n) { return u64(rpow_1[n / A]) * rpow_0[n % A] % mod; }
u32 get_pow(u64 n) { return get_pow_30(n % (mod - 1)); }
u32 H(u32 x) { return x >> 13; }; // hash func

void __attribute__((constructor)) init_table() {
  rpow_0[0] = rpow_1[0] = 1;
  FOR(i, A) rpow_0[i + 1] = u64(rpow_0[i]) * r % mod;
  FOR(i, A) rpow_1[i + 1] = u64(rpow_1[i]) * rpow_0[A] % mod;
  FOR(i, B) {
    u32 x = get_pow_30(A * i);
    int k = H(x);
    while (AX[k]) ++k;
    AX[k] = x, AI[k] = i;
  }
  FOR(i, A) {
    u32 x = get_pow_30(B * i);
    int k = H(x);
    while (BX[k]) ++k;
    BX[k] = x, BI[k] = i;
  }
}

// 掛け算 17 回 + hashmap 2 回
// 10^7 回 0.6 sec
int mod_log_998_primitive_root(modint998 a) {
  // a^A は 1 の B 乗根なので pow(r, xA) と書ける
  modint998 b = a;
  FOR(15) b *= b;
  int k = H(b.val);
  while (AX[k] != b.val) ++k;
  int x = AI[k];
  // ar^{-x} は 1 の A 乗根なので pow(r, yB) と書ける
  a *= get_pow_30(mod - 1 - x);
  k = H(a.val);
  while (BX[k] != a.val) ++k;
  int y = BI[k];
  return x + y * B;
}

int mod_log_998(int a, int b) {
  int x = mod_log_998_primitive_root(a);
  int y = mod_log_998_primitive_root(b);
  int m = 998244353 - 1;
  int g = gcd(x, m);
  if (y % g != 0) return -1;
  x /= g, y /= g, m /= g;
  return mod_inv(x, g) * y % m;
}

u32 mod_pow_998_primitive_root(u64 n) { return get_pow(n); }
} // namespace DISCRETE_LOG_998
using DISCRETE_LOG_998::mod_pow_998_primitive_root;
using DISCRETE_LOG_998::mod_log_998_primitive_root;
using DISCRETE_LOG_998::mod_log_998;
