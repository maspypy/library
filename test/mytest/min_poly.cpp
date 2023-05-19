#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "linalg/spmat_min_poly.hpp"
#include "linalg/implicit_matrix/min_poly.hpp"
#include "linalg/mat_mul.hpp"

using mint = modint998;

void test() {
  vc<tuple<int, int, mint>> A;
  A.eb(0, 0, 1);
  A.eb(0, 1, 2);
  A.eb(1, 0, 3);
  A.eb(1, 1, 4);
  vc<mint> f = spmat_min_poly<mint>(2, A);
  assert(f == vc<mint>({-2, -5, 1}));

  A.clear();
  A.eb(0, 1, 1);
  f = spmat_min_poly<mint>(2, A);
  assert(f == vc<mint>({0, 0, 1}));
  assert(f == implicit_matrix_min_poly<mint>(2, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(2);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  A.clear();
  f = spmat_min_poly<mint>(2, A);
  assert(f == vc<mint>({0, 1}));
  assert(f == implicit_matrix_min_poly<mint>(2, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(2);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  A.clear();
  f = spmat_min_poly<mint>(0, A);
  assert(f == vc<mint>({1}));
  assert(f == implicit_matrix_min_poly<mint>(0, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(0);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  A.clear();
  A.eb(0, 1, 1);
  A.eb(0, 2, 1);
  A.eb(1, 2, 1);
  f = spmat_min_poly<mint>(3, A);
  assert(f == vc<mint>({0, 0, 0, 1}));
  assert(f == implicit_matrix_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(3);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  A.clear();
  A.eb(0, 2, 1);
  f = spmat_min_poly<mint>(3, A);
  assert(f == vc<mint>({0, 0, 1}));
  assert(f == implicit_matrix_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(3);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  A.clear();
  f = spmat_min_poly<mint>(3, A);
  assert(f == vc<mint>({0, 1}));
  assert(f == implicit_matrix_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {
           vc<mint> b(3);
           for (auto&& [i, j, x]: A) b[j] += a[i] * x;
           return b;
         }));

  // random matrix
  FOR(N, 1, 20) {
    vv(mint, mat, N, N);
    FOR(i, N) FOR(j, N) mat[i][j] = RNG(0, 998244353);
    A.clear();
    FOR(i, N) FOR(j, N) A.eb(i, j, mat[i][j]);
    f = spmat_min_poly(N, A);
    assert(f == implicit_matrix_min_poly<mint>(N, [&](vc<mint> a) -> vc<mint> {
             vc<mint> b(N);
             for (auto&& [i, j, x]: A) b[j] += a[i] * x;
             return b;
           }));
    vv(mint, B, N, N);
    FOR(i, N) B[i][i] = 1;
    vv(mint, C, N, N);
    FOR(d, len(f)) {
      FOR(i, N) FOR(j, N) C[i][j] += f[d] * B[i][j];
      B = mat_mul(mat, B);
    }
    FOR(i, N) FOR(j, N) assert(C[i][j] == mint(0));
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
