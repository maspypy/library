#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/gcd.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  SegTree<Monoid_Gcd<ll>> seg(A);
  ll ANS1 = 0;
  FOR(L, N) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto R = seg.max_right(check, L);
    ANS1 += N - R;
  }
  ll ANS2 = 0;
  FOR3(R, 1, N + 1) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto L = seg.min_left(check, R);
    ANS2 += L;
  }
  assert(ANS1 == ANS2);
  print(ANS1);
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
