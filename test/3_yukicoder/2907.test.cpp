#define PROBLEM "https://yukicoder.me/problems/no/2907"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/transpose.hpp"
#include "mod/modint.hpp"
#include "nt/nimber/base.hpp"

using F = Nimber64;
using V = array<F, 18>;
using MAT = array<array<F, 18>, 18>;

void add(MAT &B, V X) {
  FOR(i, 18) {
    if (B[i][i] == F(0)) {
      if (X[i] == F(0)) continue;
      F c = X[i].inverse();
      X[i] = 1;
      FOR(j, i + 1, 18) X[j] *= c;
      B[i] = X;
    }
    F c = X[i];
    X[i] = 0;
    FOR(j, i + 1, 18) X[j] -= B[i][j] * c;
  }
}

int basis_rank(MAT &B) {
  int ans = 0;
  FOR(i, 18) if (B[i][i] == F(1))++ ans;
  return ans;
}

void solve() {
  LL(W, H);
  vv(F, A, H, W, F(0));
  FOR(x, H) FOR(y, W) {
    U64(w);
    A[x][y] = F(w - 1);
  }
  // ll r = matrix_rank<F>(mat);

  // N 変数
  // 自由度

  /*
  連立方程式の解なのだが、どの成分も 0 ではないという条件がつく！！！
  雑な方法：すべての subset で求めて包除する

  適当な列集合だけとりだしたときのランクということに？
  */

  int N = W;
  A = transpose(A);

  vc<V> rows(N);
  FOR(i, N) { FOR(j, H) rows[i][j] = A[i][j]; }

  using mint = modint998;

  mint ans = 0;
  auto dfs = [&](auto &dfs, int s, int k, MAT basis) -> void {
    if (k == N) {
      ll r = basis_rank(basis);
      ll n = popcnt(s) - r;
      mint x = mint(2).pow(64 * n);
      if ((N - popcnt(s)) % 2 == 0) {
        ans += x;
      } else {
        ans -= x;
      }
      return;
    }
    dfs(dfs, s, k + 1, basis);
    add(basis, rows[k]);
    dfs(dfs, s | 1 << k, k + 1, basis);
  };

  MAT basis{};
  dfs(dfs, 0, 0, basis);
  print(ans);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}