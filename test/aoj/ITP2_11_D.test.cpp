#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/for_nck.hpp"

void solve() {
  LL(N, K);
  FOR_nCk(s, N, K) {
    vi I;
    FOR(i, N) if (s & 1 << i) I.eb(i);
    print(to_string(s) + ":", I);
  }
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
