#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "poly/fps_log.hpp"

void solve() {
  using mint = dmint;
  mint::set_mod(998244353);
  LL(N);
  VEC(mint, f, N);
  auto ANS = fps_log(f);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
