#define PROBLEM "https://yukicoder.me/problems/no/1625"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree2d.hpp"
#include "alg/monoid/max.hpp"

void solve() {
  LL(N, Q);

  using QT = tuple<ll, ll, ll>;
  vc<QT> query;
  FOR(N) {
    LL(a, b, c, d, e, f);
    ll x = min({a, c, e});
    ll y = max({a, c, e});
    ll area = abs((c - a) * (f - b) - (e - a) * (d - b));
    query.eb(x, y, area);
  }
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(a, b, c, d, e, f);
      ll x = min({a, c, e});
      ll y = max({a, c, e});
      ll area = abs((c - a) * (f - b) - (e - a) * (d - b));
      query.eb(x, y, area);
    }
    if (t == 2) {
      LL(l, r);
      ++r;
      query.eb(-1, l, r);
    }
  }
  using Mono = Monoid_Max<ll>;
  vi X, Y, V;
  FOR(i, N) {
    auto [a, b, c] = query[i];
    X.eb(a), Y.eb(b), V.eb(c);
  }
  FOR(i, N, N + Q) {
    auto&& [a, b, c] = query[i];
    if (a != -1) X.eb(a), Y.eb(b), V.eb(Mono::unit());
  }
  SegTree2D<Mono, ll, false> seg(X, Y, V);

  FOR(q, N, N + Q) {
    auto&& [a, b, c] = query[q];
    if (a != -1) {
      seg.multiply(a, b, c);
    } else {
      ll ANS = seg.prod(b, c, b, c);
      if (ANS == Mono::unit()) ANS = -1;
      print(ANS);
    }
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
