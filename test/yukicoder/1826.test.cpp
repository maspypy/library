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

  ll LIM = 1LL << 32;
  Dynamic_SegTree<Monoid_Max<ll>> seg(-LIM, LIM);
  seg.set(0, 0);

  FOR(i, N) {
    ll x = X[i], y = Y[i], v = V[i];
    if (x < 0) continue;
    ll t = seg.prod(-LIM, y + 1) + v;
    seg.multiply(y, t);
  }
  print(seg.prod_all());
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
