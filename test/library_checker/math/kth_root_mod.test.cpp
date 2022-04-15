#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/mod_kth_root.hpp"

void solve() {
  LL(k, y, p);
  ll x = mod_kth_root(k, y % p, p);
  print(x);
}

signed main() {
  LL(T);
  FOR_(T) solve();

  return 0;
}
