#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/bitset/mat_inv.hpp"

using BS = My_Bitset;

void solve() {
  LL(N);
  vc<BS> mat(N);
  FOR(i, N) {
    STR(S);
    mat[i].resize(N);
    FOR(j, N) mat[i][j] = (S[j] == '1');
  }
  mat = mat_inv(mat);
  if (mat.empty()) return print(-1);
  FOR(i, N) print(mat[i].to_string());
}

signed main() {
  solve();
  return 0;
}
