#define PROBLEM "https://yukicoder.me/problems/no/1625"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree_2d.hpp"
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
  SegTree_2D<Mono, ll, false> seg(N + Q, [&](int i) -> tuple<ll, ll, ll> {
    auto [a, b, c] = query[i];
    if (i < N) return {a, b, c};
    return {a, b, Mono::unit()};
  });

  FOR(q, N, N + Q) {
    auto&& [a, b, c] = query[q];
    if (a != -1) {
      seg.multiply(q, c);
    } else {
      ll ANS = seg.prod(b, c, b, c);
      if (ANS == Mono::unit()) ANS = -1;
      print(ANS);
    }
  }
}

signed main() {
  solve();
  return 0;
}
