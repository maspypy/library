#define PROBLEM "https://yukicoder.me/problems/no/187"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/lcm.hpp"
#include "nt/crt.hpp"

void solve() {
  LL(N);
  vc<int> vals, mods;
  FOR(i, N) {
    LL(a, b);
    vals.eb(a);
    mods.eb(b);
  }

  if (MAX(vals) == 0) { return print(LCM(mods, 1000000007)); }
  print(CRT(vals, mods, 1000000007, 0));
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
