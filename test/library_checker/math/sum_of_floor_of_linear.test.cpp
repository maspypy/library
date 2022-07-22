#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/floor_sum_of_linear.hpp"

void solve() {
  LL(N, mod, a, b);
  print(floor_sum_of_linear(0, N, a, b, mod));
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
