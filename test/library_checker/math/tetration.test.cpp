#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/tetration.hpp"

void solve() {
  LL(a, b, m);
  if (a == 0) {
    ll ANS = (b % 2 == 0 ? 1 : 0);
    return print(ANS % m);
  }
  chmin(b, 64);
  vi v(b, a);
  print(tetration(v, m));
}

signed main() {
  LL(T);
  FOR_(T) solve();

  return 0;
}
