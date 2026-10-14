#define PROBLEM "https://yukicoder.me/problems/no/2890"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/add_chmin_chmax_with_cost.hpp"

void solve() {
  LL(N, K);
  N += N;
  VEC(ll, A, K);
  FOR_R(i, K) A[i] -= A[0];
  A.eb(N + A[0]);
  A.eb(N + A[1]);

  using Mono = Monoid_Add_Chmin_Chmax_with_Cost<ll>;
  using F = Mono::value_type;

  // 奇数出発
  auto check = [&](ll D) -> bool {
    if (D % 2 == 1) ++D;
    SegTree<Mono> seg(K, [&](int i) -> F {
      ll L = A[i + 1] + 1, R = A[i + 2] - 1;
      // x -> clamp(x + D, L, R)
      return Mono::add_clamp(D, L, R);
    });
    F f = seg.prod_all();
    FOR(x, 0, A[1]) {
      if (x % 2 == 0) continue;
      auto [y, chmax_cost, chmin_cost] = Mono::eval(f, x);
      if (y > x + N) continue;
      if (chmin_cost > 0) continue;
      return 1;
    }
    return 0;
  };
  ll ANS = binary_search(check, 0, N);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
