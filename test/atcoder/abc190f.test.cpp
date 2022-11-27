#define PROBLEM "https://atcoder.jp/contests/abc190/tasks/abc190_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwick.hpp"
#include "seq/inversion_rotate.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  vi ANS = inversion_rotate(A, true);
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
