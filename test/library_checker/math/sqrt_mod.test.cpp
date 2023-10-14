#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/mod_sqrt.hpp"

void solve() {
  INT(y, p);
  print(mod_sqrt(y, p));
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}