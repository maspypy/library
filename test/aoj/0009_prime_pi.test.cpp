#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"
#include "my_template.hpp"
#include "other/io2.hpp"

#include "nt/primesum.hpp"

void solve() {
  ll N;
  while (cin >> N) {
    auto [lo, hi] = primecnt<ll>(N);
    print(hi[1]);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
