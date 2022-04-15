#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/sharp_p_subset_sum.hpp"

using mint = modint998;
void solve() {
  LL(N, T);
  VEC(int, S, N);
  auto f = sharp_p_subset_sum<mint>(S, T + 1);
  f.erase(f.begin());
  print(f);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
