#define PROBLEM "https://yukicoder.me/problems/no/2259"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/min_of_linear.hpp"

void solve() {
  LL(L, R, C);
  auto [x, fx] = min_of_linear(L, R + 1, -C, 0, 1000);
  print(fx);
}

signed main() {
  solve();
  return 0;
}