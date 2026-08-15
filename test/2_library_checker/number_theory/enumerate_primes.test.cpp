#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/prime_table.hpp"

void solve() {
  LL(N, A, B);
  auto primes = prime_table(N);
  int pi_N = UB(primes, N);

  vc<int> ANS;
  while (B < pi_N) {
    ANS.eb(primes[B]);
    B += A;
  }
  print(pi_N, len(ANS));
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
