#define PROBLEM "https://yukicoder.me/problems/no/1936"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/ext_gcd.hpp"

void solve() {
  LL(P, Q);
  auto [a, b, c, d] = farey_lr(P, Q);
  print(a + b + c + d);
}

signed main() {
  solve();
  return 0;
}
