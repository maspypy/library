#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primesum.hpp"

void solve() {
  LL(N);
  PrimeSum<ll> X(N);
  X.count();
  print(X[N]);
}

signed main() {
  solve();

  return 0;
}
