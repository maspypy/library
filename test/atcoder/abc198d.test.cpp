#define PROBLEM "https://atcoder.jp/contests/abc198/tasks/abc198_d"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/solve_hukumenzan.hpp"

void solve() {
  STR(A, B, C);
  auto res = solve_hukumenzan(A, B, C);
  if (len(res) == 0) return print("UNSOLVABLE");
  auto [a, b, c] = res[0];
  print(a);
  print(b);
  print(c);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
