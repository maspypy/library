#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/random_matrix.hpp"
#include "linalg/blackbox/solve_linear.hpp"

using mint = modint998;

void test() {
  FOR(100) {
    FOR(N, 1, 10) FOR(M, 1, 10) FOR(R, 0, 10) {
      if (R > N || R > M) continue;
      vvc<mint> A = random_matrix<mint>(N, M, R);
      vc<tuple<int, int, mint>> mat;
      FOR(i, N) FOR(j, M) mat.eb(i, j, A[i][j]);
      vc<mint> x(N), y(M);
      FOR(i, M) y[i] = RNG(0, mint::get_mod());
      FOR(i, N) FOR(j, M) x[i] += A[i][j] * y[j];
      if (RNG(0, 2) == 0) { FOR(i, M) y[i] = RNG(0, 2); }
      int fail = 0;
      FOR(5) {
        vc<mint> ans = sparse_solve_linear<mint>(N, M, mat, x);
        if (ans.empty()) ++fail;
      }
      assert(fail <= 1);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}