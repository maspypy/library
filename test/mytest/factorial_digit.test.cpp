#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/factorial_digit_system.hpp"

void test() {
  FOR(N, 1, 7) {
    vc<int> pre = {-1, 0, 0, 0};
    vc<int> A(N);
    iota(all(A), 0);
    do {
      vc<int> B = to_factorial_digit_system(A);
      vc<int> C = from_factorial_digit_system(B);
      assert(A == C);
      assert(pre < B);
      pre = B;
    } while (next_permutation(all(A)));
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}