#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/inversion.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll x = inversion<ll, false>(A);
  sort(all(A));
  print(A);
  print(x);
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
