#define PROBLEM "https://yukicoder.me/problems/no/1826"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/max.hpp"

void solve() {
  LL(N);
  vi X, Y, V;
  FOR(N) {
    LL(t, x, v);
    X.eb(t - x), Y.eb(t + x), V.eb(v);
  }

  auto I = argsort(X);
  X = rearrange(X, I), Y = rearrange(Y, I), V = rearrange(V, I);

  ll LIM = 1LL << 31;
  Dynamic_SegTree<Monoid_Max<ll>, false> seg(35 * (N + 1), -LIM, LIM);
  auto root = seg.new_node(-LIM, LIM);
  root = seg.set(root, 0, 0);

  FOR(i, N) {
    ll x = X[i], y = Y[i], v = V[i];
    if (x < 0) continue;
    ll t = seg.prod(root, -LIM, y + 1) + v;
    root = seg.multiply(root, y, t);
  }
  print(root->x);
}

signed main() {
  solve();
  return 0;
}
