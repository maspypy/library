#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree_2d.hpp"
#include "alg/monoid/max.hpp"

using Mono = Monoid_Max<ll>;

void solve() {
  LL(N);
  using T = tuple<ll, ll, ll, ll>;

  VEC(T, dat, N);
  dat.eb(0, 0, 0, 0);
  ++N;

  sort(all(dat), [&](auto& a, auto& b) -> bool {
    auto [at, ax, ay, aa] = a;
    auto [bt, bx, by, bb] = b;
    if (ay < by) return true;
    if (ay > by) return false;
    return at < bt;
  });

  SegTree_2D<Mono, ll, false> seg1(N, [&](int i) -> tuple<int, int, ll> {
    auto [t, x, y, v] = dat[i];
    return {x, x + y - t, Mono::unit()};
  });
  SegTree_2D<Mono, ll, false> seg2(N, [&](int i) -> tuple<int, int, ll> {
    auto [t, x, y, v] = dat[i];
    return {x, x - y + t, Mono::unit()};
  });

  ll ANS = 0;
  FOR(i, N) {
    const auto [t, x, y, v] = dat[i];
    if (i == 0) {
      seg1.multiply(i, 0);
      seg2.multiply(i, 0);
      continue;
    }
    ll best = -infty<ll>;
    chmax(best, seg1.prod(-infty<ll>, x + 1, x + y - t, infty<ll>));
    chmax(best, seg2.prod(x, infty<ll>, -infty<ll>, x - y + t + 1));
    if (best < 0) continue;
    best += v;
    chmax(ANS, best);
    seg1.multiply(i, best);
    seg2.multiply(i, best);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
