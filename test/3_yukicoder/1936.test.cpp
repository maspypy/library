#define PROBLEM "https://yukicoder.me/problems/no/1936"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/extgcd.hpp"

void solve() {
  LL(P, Q);
  auto [a, b, c, d] = Farey_lr(P, Q);
  print(a + b + c + d);
}

signed main() {
  solve();
  return 0;
}
