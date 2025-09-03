#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/hafnian.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VV(mint, B, N, N);
  auto ANS = Hufnian(B);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
