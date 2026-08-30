#include "other/bit.hpp"

struct Binomial_u64 {
  int LIM;
  vc<u64> fact, ifact, exp;
  Binomial_u64(int LIM)
      : LIM(LIM), fact(LIM + 1), ifact(LIM + 1), exp(LIM + 1) {
    fact[0] = 1;
    for (int i = 1; i <= LIM; ++i) {
      int k = lowbit(i);
      fact[i] = fact[i - 1] * (i >> k);
      exp[i] = exp[i - 1] + k;
    }
    ifact[LIM] = mod_inv_u64(fact[LIM]);
    for (u64 i = LIM; i >= 1; --i) {
      int k = lowbit(i);
      ifact[i - 1] = ifact[i] * (i >> k);
    }
  }

  u64 C(int n, int k) {
    assert(0 <= n);
    if (k < 0 || n < k) return 0;
    int e = exp[n] - exp[k] - exp[n - k];
    u64 x = fact[n] * ifact[k] * ifact[n - k];
    return x << e;
  }
};