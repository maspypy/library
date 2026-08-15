#include "nt/prime_table.hpp"

// [0, LIM], 0, 1 には -1 が入る。
vc<int> lpf_table(ll LIM) {
  auto primes = prime_table(LIM);
  vc<int> res(LIM + 1, -1);
  FOR_R(i, len(primes)) {
    auto p = primes[i];
    FOR3(j, 1, LIM / p + 1) res[p * j] = p;
  }
  return res;
}
