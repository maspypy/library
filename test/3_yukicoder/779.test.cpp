#define PROBLEM "https://yukicoder.me/problems/no/779"
#include "my_template.hpp"
#include "other/io.hpp"

#include "datetime/datetime.hpp"

using DT = DateTime;

void solve() {
  LL(y, m, d);
  DT X(y, m, d);
  Yes(DT(1989, 1, 8) <= X && X <= DT(2019, 4, 30));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
