#define PROBLEM "https://atcoder.jp/contests/abc152/tasks/abc152_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/all_lcm.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  mint ANS = 0;
  for (auto&& a: A) ANS += mint(a).inverse();
  print(ANS * all_lcm<mint>(A, false));
}

signed main() {
  solve();
  return 0;
}