#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/multipoint.hpp"

#include "mod/modint.hpp"
using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, f, N);
  VEC(mint, pts, M);
  print(multipoint_eval(f, pts));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
