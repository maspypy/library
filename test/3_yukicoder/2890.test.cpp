#define PROBLEM "https://yukicoder.me/problems/no/2890"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/add_chmin_chmax_with_cost.hpp"

// x をうつしたとき, add による変化量が a
// chmax による増加量が b + max(x1-x,0)
// chmin による減少量が c + max(x-x2,0)
// struct F {
//   T a, b, c, x1, x2;
// }

void solve() {
  LL(N, K);
  N += N;
  VEC(ll, A, K);
  FOR_R(i, K) A[i] -= A[0];
  A.eb(N + A[0]);
  A.eb(N + A[1]);

  using Mono = Monoid_Add_Chmin_Chmax_With_Cost<ll>;
  using F = Mono::value_type;

  SHOW(A);

  // 奇数出発
  auto check = [&](ll D) -> bool {
    if (D % 2 == 1) ++D;
    SegTree<Mono> seg(K, [&](int i) -> F {
      ll L = A[i + 1] + 1, R = A[i + 2] - 1;
      SHOW(L, R);
      // x -> clamp(x+D,L,R)
      return {D, 0, 0, L - D, R - D};
    });
    F f = seg.prod_all();
    SHOW(D, f.a, f.b, f.c, f.x1, f.x2);
    FOR(x, 0, A[1]) {
      if (x % 2 == 0) continue;
      auto [a, b, c] = f.eval_cost(x);
      ll y = f.eval(x);
      SHOW(x, a, b, c, y);
      if (y > x + N) continue;
      if (c > 0) continue;
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
