#define PROBLEM "https://yukicoder.me/problems/no/2119"

#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/crt.hpp"

void solve() {
  LL(N, M);
  vc<int> vals, mods;
  FOR(M) {
    LL(b, c);
    c %= b;
    if (c < 0) c += b;
    mods.eb(b);
    vals.eb(c);
  }
  auto ng = [&]() -> void { print("NaN"); };
  ll x = CRT(vals, mods, 998244353, false);
  FOR(i, M) {
    if (x % mods[i] != vals[i]) return ng();
  }
  if (x > N) return ng();
  print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
