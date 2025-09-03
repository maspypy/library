#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/product_of_one_plus_xn.hpp"

using mint = modint998;
void solve() {
  LL(N, T);
  VEC(int, S, N);
  auto f = product_of_one_plus_xn<mint>(S, T);
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
