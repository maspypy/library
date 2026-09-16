#include "nt/prime_table.hpp"

// [0, LIM], 0, 1 には -1 が入る。
vc<int> spf_table(int LIM) {
  auto primes = prime_table(LIM);
  vc<int> spf(LIM + 1, -1);
  int sq = sqrt(LIM);
  for (int i = 2; i <= LIM; i += 2) spf[i] = 2;
  FOR_R(i, len(primes)) {
    auto p = primes[i];
    spf[p] = p;
    if (sq < p) continue;
    for (int k = p * p; k <= LIM; k += 2 * p) spf[k] = p;
  }
  return spf;
}
