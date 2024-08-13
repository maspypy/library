#define PROBLEM "https://yukicoder.me/problems/no/2120"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/binomial.hpp"

void solve() {
  LL(M, N);
  auto out = [&](ll x) -> void {
    string s = to_string(x);
    while (len(s) < 8) s = "0" + s;
    print(s);
  };

  int mod = 100000000;
  Binomial B(mod);
  ll ans = B.C(M, N);
  out(ans);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
