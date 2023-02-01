#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "linalg/implicit_matrix/vandermonde.hpp"

template <typename mint>
vc<mint> naive(vc<mint> f, vc<mint> A, bool transpose) {
  assert(len(f) == len(A));
  int N = len(f);
  vc<mint> g(N);
  if (!transpose) { FOR(i, N) FOR(j, N) g[i] += A[i].pow(j) * f[j]; }
  if (transpose) { FOR(i, N) FOR(j, N) g[i] += A[j].pow(i) * f[j]; }
  return g;
}

using mint = modint998;
vc<mint> gen(int n) {
  vc<mint> f(n);
  set<mint> ss;
  FOR(i, n) {
    while (1) {
      mint x = RNG(-100, 100);
      if (ss.count(x)) continue;
      ss.insert(x);
      f[i] = x;
      break;
    }
  }
  return f;
}

void test() {
  FOR(t, 2) {
    FOR(n, 100) {
      auto f = gen(n), A = gen(n);
      auto g = vandermonde<mint>(f, A, t, 0);
      auto g1 = naive(f, A, t);
      assert(g == g1);
      auto f1 = vandermonde<mint>(g, A, t, 1);
      assert(f == f1);
    }
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