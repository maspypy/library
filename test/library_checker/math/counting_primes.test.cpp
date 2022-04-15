#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primesum.hpp"

void solve() {
  LL(N);
  auto [sum_lo, sum_hi] = primecnt<ll>(N);
  print(sum_hi[1]);
}

signed main() {
  solve();

  return 0;
}
