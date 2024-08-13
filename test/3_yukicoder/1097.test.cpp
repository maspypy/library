#define PROBLEM "https://yukicoder.me/problems/no/1097"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/doubling.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Doubling<Monoid_Add<ll>, 50> X(N);
  FOR(i, N) { X.add(i, (i + A[i]) % N, A[i]); }
  X.build();

  LL(Q);
  FOR(Q) {
    LL(k);
    auto [to, val] = X.calc(0, k);
    print(val);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
