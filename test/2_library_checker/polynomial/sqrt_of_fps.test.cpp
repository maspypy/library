#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_sqrt.hpp"

using mint = modint998;
void solve() {
  LL(N);
  VEC(mint, A, N);
  auto B = fps_sqrt_any(A);
  if (len(B) == N)
    print(B);
  else
    print(-1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
