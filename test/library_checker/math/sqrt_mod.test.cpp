#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/dynamic_modint.hpp"
#include "mod/mod_sqrt.hpp"

using mint = dmint;

void solve() {
  LL(T);
  FOR(T) {
    LL(y0, p);
    mint::set_mod(p);
    mint y = y0;
    mint r = mod_sqrt(y);
    if (r * r == y)
      print(r);
    else
      print(-1);
  }
}

signed main() {
  solve();
  return 0;
}
