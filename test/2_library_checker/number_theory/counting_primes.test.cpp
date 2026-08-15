#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/prime_sum.hpp"

void solve() {
  LL(N);
  Prime_Sum<ll> X(N);
  X.calc_count();
  print(X[N]);
}

signed main() {
  solve();

  return 0;
}
