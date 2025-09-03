#define PROBLEM "https://yukicoder.me/problems/no/2109"
#include "my_template.hpp"
#include "other/io.hpp"
#include "datetime/datetime.hpp"

void solve() {
  LL(M, D, K);
  DateTime x(1, M, D);
  string s;
  FOR(7) {
    string t = x.to_string();
    t = t.substr(5);
    s += t;
    ++x;
  }
  int a = 0;
  for (auto&& x: s) {
    if (x == '-') continue;
    a |= 1 << (x - '0');
  }
  Yes(popcnt(a) >= K);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
