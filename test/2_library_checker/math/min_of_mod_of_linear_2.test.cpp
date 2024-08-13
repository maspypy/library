#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/range_freq_of_linear.hpp"

void solve() {
  LL(n, m, a, b);
  auto check = [&](int k) -> bool {
    return range_freq_of_linear<i128, ll>(0, n, a, b, m, 0, k) == 0;
  };
  print(binary_search(check, 0, m));
}

signed main() {
  LL(T);
  FOR(T) solve();

  return 0;
}
