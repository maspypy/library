#define PROBLEM "https://atcoder.jp/contests/abc365/tasks/abc365_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/segtree.hpp"
#include "alg/monoid/add_chmin_chmax_with_cost.hpp"

void solve() {
  LL(N);
  vi L(N), R(N);
  FOR(i, N) read(L[i], R[i]);
  using Mono = Monoid_Add_Chmin_Chmax_With_Cost<ll>;
  using F = Mono::F;
  SegTree<Mono> seg(N, [&](int i) -> F { return F(0, 0, 0, L[i], R[i]); });
  LL(Q);
  FOR(Q) {
    LL(x1, y1, x2, y2);
    --x1, --x2;
    if (x1 > x2) swap(x1, x2), swap(y1, y2);
    F f = seg.prod(x1, x2);
    auto [a, b, c] = f.eval_cost(y1);
    ll ANS = b + c;
    y1 = y1 + a + b - c;
    ANS += abs(y1 - y2);
    ANS += abs(x1 - x2);
    print(ANS);
  }
}

signed main() { solve(); }