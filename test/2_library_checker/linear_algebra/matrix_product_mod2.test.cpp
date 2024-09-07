#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/bitset/matrix_mul_mod_2.hpp"

using BS = My_Bitset;

void solve() {
  INT(N, M, K);
  vc<BS> A(N, BS(M));
  vc<BS> B(M, BS(K));

  FOR(i, N) {
    FOR(j, M) {
      CHAR(ch);
      A[i][j] = (ch - '0');
    }
  }
  FOR(i, M) {
    FOR(j, K) {
      CHAR(ch);
      B[i][j] = (ch - '0');
    }
  }
  vc<BS> C = matrix_mul_mod_2(A, B, N, M, K);
  FOR(i, N) { print(C[i].to_string()); }
}

signed main() {
  solve();
  return 0;
}
