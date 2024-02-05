#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sparse_table/sparse_table.hpp"
#include "alg/monoid/gcd.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Sparse_Table<Monoid_Gcd<ll>> seg(A);
  ll R = 0;
  ll ANS = 0;
  FOR(L, N) {
    while (R < N && seg.prod(L, R + 1) != 1) ++R;
    ANS += N - R;
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
