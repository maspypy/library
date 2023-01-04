#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/divisors.hpp"

void solve() {
  LL(a, b, c);
  auto divs = divisors<false>(c);
  ll ANS = 0;
  for (auto&& d: divs)
    if (a <= d && d <= b) ++ANS;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
