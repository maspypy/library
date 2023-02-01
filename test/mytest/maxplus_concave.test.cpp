#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "convex/maxplus_convolution_concave.hpp"

vc<int> gen(int L, int N, int R) {
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(-100, 100);
  sort(all(A));
  reverse(all(A));
  A = cumsum<int>(A);
  FOR(L) A.insert(A.begin(), -infty<int>);
  FOR(R) A.insert(A.end(), -infty<int>);
  return A;
}

vc<int> naive(vc<int> A, vc<int> B) {
  int N = len(A), M = len(B);
  vc<int> C(N + M - 1, -infty<int>);
  FOR(i, N) FOR(j, M) {
    if (A[i] == -infty<int> || B[j] == -infty<int>) continue;
    chmax(C[i + j], A[i] + B[j]);
  }
  return C;
}

void test() {
  FOR(a1, 5) FOR(b1, 10) FOR(c1, 5) {
    vc<int> A = gen(a1, b1, c1);
    FOR(a2, 5) FOR(b2, 10) FOR(c2, 5) {
      vc<int> B = gen(a2, b2, c2);
      vc<int> C = maxplus_convolution_concave<int, true, true>(A, B);
      assert(naive(A, B) == C);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
