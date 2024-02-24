#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_bitset.hpp"

using BS = My_Bitset;

void solve() {
  INT(N, M, K);

  vc<BS> A(N, BS(M));
  vc<BS> B(M, BS(K));
  vc<BS> C(N, BS(K));

  FOR(i, N) {
    FOR(j, M) {
      CHAR(ch);
      A[i][j] = ch - '0';
    }
  }
  FOR(j, M) {
    FOR(k, K) {
      CHAR(ch);
      B[j][k] = ch - '0';
    }
  }
  FOR(i, N) FOR(j, M) {
    if (A[i][j]) C[i] ^= B[j];
  }
  FOR(i, N) { print(C[i].to_string()); }
}

signed main() {
  solve();
  return 0;
}