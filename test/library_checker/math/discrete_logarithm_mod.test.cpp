#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/mod_log.hpp"

void solve() {
  LL(x, y, mod);
  print(mod_log(mod, x, y));
}

signed main() {
  LL(T);
  FOR_(T) solve();

  return 0;
}
