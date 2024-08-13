#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/divisors.hpp"

void solve() {
  LL(a, b, c);
  auto divs = divisors(c);
  ll ANS = 0;
  for (auto&& d: divs)
    if (a <= d && d <= b) ++ANS;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}