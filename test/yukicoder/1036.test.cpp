#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/gcd.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto f = [&](ll L, ll R) -> ll { return 0; };
  Dynamic_SegTree<Monoid_Gcd<ll>> seg(0, N, f);
  FOR(i, N) seg.set(i, A[i]);

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
