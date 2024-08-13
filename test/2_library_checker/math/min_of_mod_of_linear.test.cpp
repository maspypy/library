#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/min_of_linear.hpp"

void solve() {
  LL(n, m, a, b);
  auto [x, fx] = min_of_linear(0, n, a, b, m);
  print(fx);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}