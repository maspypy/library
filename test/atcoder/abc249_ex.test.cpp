#define PROBLEM "https://atcoder.jp/contests/abc249/tasks/abc249_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/powertable.hpp"
#include "linalg/solve_linear_lower.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(ll, A, N);
  for (auto&& x: A) --x;
  vi CNT(N);
  for (auto&& x: A) CNT[x]++;
  vc<mint> iPOW = powertable_1<mint>(mint(2).inverse(), N);

  auto f = [&]() -> vc<mint> {
    // いま x 個であるものをコンプする回数期待値 f(x) を求める
    vv(mint, mat, N + 1, N + 1);
    vc<mint> rhs(N + 1, mint(1));
    rhs[N] = mint(0);
    mat[N][N] = mint(1);
    FOR(x, N) {
      mat[x][x] = 1;
      mint p = mint(x) * inv<mint>(N);
      FOR(y, x) { mat[x][y + 1] -= p * iPOW[x - 1] * C<mint, 0, 1>(x - 1, y); }
      p = mint(N - x) * inv<mint>(N);
      FOR(y, x + 1) {
        mat[x][y] -= p * iPOW[x + 1] * C<mint, 0, 1>(x, y);
        mat[x][y + 1] -= p * iPOW[x + 1] * C<mint, 0, 1>(x, y);
      }
    }
    vv(mint, sub, N, N);
    FOR(i, N) FOR(j, N) sub[i][j] = mat[i][j + 1];
    vc<mint> x = solve_linear_lower(sub, vc<mint>(N, mint(1)));
    x.insert(x.begin(), mint(0));
    mint add = -mint(x.back());
    for (auto&& a: x) a += add;
    return x;
  }();
  mint ANS = 0;
  FOR(i, N) ANS += f[CNT[i]];
  ANS -= mint(N - 1) * f[0];
  ANS /= mint(N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}
