#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_c"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/rot90.hpp"

void solve() {
  LL(N);
  VEC(string, A, N);
  VEC(string, B, N);
  FOR(4) {
    while (count(all(A.back()), '#') == 0) POP(A);
    while (count(all(B.back()), '#') == 0) POP(B);
    A = rot90(len(A), len(A[0]), A);
    B = rot90(len(B), len(B[0]), B);
  }

  FOR(4) {
    A = rot90(len(A), len(A[0]), A);
    if (A == B) return Yes();
  }
  No();
}

signed main() {
  solve();
  return 0;
}