#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/primetable.hpp"

void solve() {
  LL(N, A, B);
  auto primes = primetable(N);
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
