#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/extgcd.hpp"

void solve() {
  LL(a, b);
  auto [x, y, d] = extgcd2(a, b);
  print(x, y);
}

signed main() {
  solve();
  return 0;
}
