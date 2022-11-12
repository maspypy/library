#define PROBLEM "https://atcoder.jp/contests/abc276/tasks/abc276_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/cumsum2d.hpp"
#include "linalg/solve_linear_F2.hpp"

void solve() {
  LL(N, Q);
  using T = tuple<int, int, int, int, int>;
  vc<T> dat;
  FOR(Q) {
    LL(a, b, c, d, e);
    --a, --c;
    dat.eb(a, b, c, d, e);
  }

  auto idx = [&](int i, int j) -> int { return (N + 1) * i + j; };

  // 4 つ組 -> 2 の個数の偶奇
  vc<T> eqs;
  for (auto&& [a, b, c, d, e]: dat) {
    if (e == 0) continue;
    int x0 = idx(a, c);
    int x1 = idx(a, d);
    int x2 = idx(b, c);
    int x3 = idx(b, d);
    eqs.eb(x0, x1, x2, x3, (e == 1 ? 0 : 1));
  }
  vc<int> X;
  for (auto&& [a, b, c, d, e]: eqs) X.eb(a), X.eb(b), X.eb(c), X.eb(d);
  UNIQUE(X);
  for (auto&& [a, b, c, d, e]: eqs) {
    a = LB(X, a);
    b = LB(X, b);
    c = LB(X, c);
    d = LB(X, d);
  }

  vv(bool, mat, len(eqs), len(X));
  vc<bool> y(len(eqs));
  FOR(i, len(eqs)) {
    auto [a, b, c, d, e] = eqs[i];
    mat[i][a] = 1;
    mat[i][b] = 1;
    mat[i][c] = 1;
    mat[i][d] = 1;
    y[i] = e;
  }

  vv(int, ANS2, N, N);

  if (len(eqs)) {
    auto sol = solve_linear_F2<8000>(len(eqs), len(X), mat, y);
    if (sol.empty()) return No();
    auto x = sol[0];
    // とりあえず作る
    vv(int, B, N + 1, N + 1);
    FOR(i, len(X)) {
      auto idx = X[i];
      auto [h, w] = divmod(idx, N + 1);
      B[h][w] = x[i];
    }
    FOR(x, N + 1) {
      if (B[x][0] == 1) {
        FOR(y, N + 1) { B[x][y] ^= 1; }
      }
    }
    FOR(y, N + 1) {
      if (B[0][y] == 1) {
        FOR(x, N + 1) { B[x][y] ^= 1; }
      }
    }
    // FOR(x, N + 1) print(B[x]);

    // 2^a を表す 01 ベクトル
    FOR(i, N) FOR(j, N) {
      ANS2[i][j] ^= B[i][j];
      ANS2[i][j] ^= B[i][j + 1];
      ANS2[i][j] ^= B[i + 1][j];
      ANS2[i][j] ^= B[i + 1][j + 1];
    }
  }
  // 0 でないことを表す 01 ベクトル
  vv(int, ANS1, N + 1, N + 1);
  for (auto&& [a, b, c, d, e]: dat) {
    if (e == 0) continue;
    ANS1[a][c] += 1;
    ANS1[a][d] -= 1;
    ANS1[b][c] -= 1;
    ANS1[b][d] += 1;
  }
  FOR(x, N + 1) { FOR(y, N) ANS1[x][y + 1] += ANS1[x][y]; }
  FOR(y, N + 1) { FOR(x, N) ANS1[x + 1][y] += ANS1[x][y]; }
  ANS1.resize(N);
  FOR(i, N) ANS1[i].resize(N);
  FOR(i, N) FOR(j, N) { ANS1[i][j] = (ANS1[i][j] == 0 ? 0 : 1); }

  // 0 の条件をチェックする
  Cumsum2D<Group_Add<int>> CS(ANS1);
  for (auto&& [a, b, c, d, e]: dat) {
    if (e != 0) continue;
    ll cnt = CS.sum(a, c, b, d);
    if (cnt == (b - a) * (d - c)) return No();
  }

  vv(int, ANS, N, N);
  FOR(i, N) FOR(j, N) {
    if (ANS1[i][j] == 0) continue;
    ANS[i][j] = (ANS2[i][j] == 1 ? 2 : 1);
  }
  Yes();
  FOR(x, N) print(ANS[x]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}