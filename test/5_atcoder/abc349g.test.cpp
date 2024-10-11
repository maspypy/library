#define PROBLEM "https://atcoder.jp/contests/abc349/tasks/abc349_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/inverse_manacher.hpp"

void solve() {
  LL(N);
  VEC(int, R, N);
  for (auto& x: R) x = 2 * x + 1;
  auto A = inverse_manacher(R);
  if (A.empty()) { return No(); }

  for (auto& x: A) ++x;
  Yes();
  print(A);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
