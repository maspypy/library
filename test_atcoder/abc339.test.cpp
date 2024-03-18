#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_g"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Dynamic_SegTree_Sparse<Monoid_Add<ll>, false, 50'000'000> seg(0,
                                                                infty<int> + 1);
  using np = decltype(seg)::np;

  vc<np> ROOT(2 * N);
  FOR(i, 2 * N) ROOT[i] = seg.new_root();

  auto add = [&](int i, ll x) -> void {
    i += N;
    while (i) {
      ROOT[i] = seg.multiply(ROOT[i], x, x);
      i /= 2;
    }
  };

  auto rm = [&](int i, ll x) -> void {
    i += N;
    while (i) {
      ROOT[i] = seg.multiply(ROOT[i], x, -x);
      i /= 2;
    }
  };

  auto query = [&](int L, int R, ll x) -> ll {
    ll ANS = 0;
    L += N, R += N;
    while (L < R) {
      if (L & 1) { ANS += seg.prod(ROOT[L++], 0, x + 1); }
      if (R & 1) { ANS += seg.prod(ROOT[--R], 0, x + 1); }
      L /= 2, R /= 2;
    }
    return ANS;
  };

  FOR(i, N) add(i, A[i]);

  LL(Q);
  ll last_ans = 0;
  FOR(Q) {
    LL(a, b, c);
    a ^= last_ans;
    b ^= last_ans;
    c ^= last_ans;
    --a;
    ll ans = query(a, b, c);
    last_ans = ans;
    print(ans);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
