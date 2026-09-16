#include "nt/prime_table.hpp"

// [0, LIM], 0, 1 には -1 が入る。
vc<int> lpf_table(ll LIM) {
  auto primes = prime_table(LIM);
  vc<int> res(LIM + 1, -1);
  int sq = sqrt(LIM);
  FOR_R(i, len(primes)) {
    auto p = primes[i];
    res[p] = p;
    if (sq < p) continue;
    for (int k = p * p; k <= LIM; k += p) res[k] = p;
  }
  return res;
}
