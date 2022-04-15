#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/mod_sqrt.hpp"

using mint = amint;

void solve() {
  LL(T);
  FOR_(T) {
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
