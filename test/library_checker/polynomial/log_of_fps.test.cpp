#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/fps_log.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, f, N);
  auto ANS = fps_log(f);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
