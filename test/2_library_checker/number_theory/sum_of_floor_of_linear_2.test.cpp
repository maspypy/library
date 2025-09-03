#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/floor_sum_of_linear_polynomial.hpp"

void solve() {
  u32 n, m, a, b;
  read(n, m, a, b);
  auto x = floor_sum_of_linear_polynomial_nonnegative<u64, 0, 1, u64>(n, a, b, m);
  print(x[0][1]);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
