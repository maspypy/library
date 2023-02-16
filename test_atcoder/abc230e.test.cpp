#define PROBLEM "https://atcoder.jp/contests/abc230/tasks/abc230_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/sigma_0_sum.hpp"

void solve() {
  LL(N);
  print(sigma_0_sum(N));
}

signed main() {
  solve();
  return 0;
}
