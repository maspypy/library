#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree_2d.hpp"
#include "alg/monoid/max.hpp"

using Mono = Monoid_Max<ll>;

void naive() {
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

  vi dp(N, -infty<ll>);
  dp[0] = 0;
  FOR(j, N) {
    auto [tj, xj, yj, vvj] = dat[j];
    FOR(i, j) {
      auto [ti, xi, yi, vvi] = dat[i];
      ll d = abs(xi - xj) + abs(yi - yj);
      if (yi > yj) continue;
      if (ti + d > tj) continue;
      chmax(dp[j], dp[i] + vvj);
    }
    print(tj, xj, yj, vvj, dp[j]);
  }
  print(MAX(dp));
}

void solve() {
  // return naive();

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

  vi X1(N), Y1(N), X2(N), Y2(N);
  FOR(i, N) {
    auto [t, x, y, v] = dat[i];
    X1[i] = x;
    X2[i] = x;
    Y1[i] = x + y - t;
    Y2[i] = x - y + t;
  }
  SegTree_2D<Mono, ll, false> seg1(X1, Y1);
  SegTree_2D<Mono, ll, false> seg2(X2, Y2);

  ll ANS = 0;
  FOR(i, N) {
    const auto [t, x, y, v] = dat[i];
    const ll a = x, b = y, c = t;
    if (i == 0) {
      seg1.multiply(a, a + b - c, 0);
      seg2.multiply(a, a - b + c, 0);
      continue;
    }
    ll best = -infty<ll>;
    chmax(best, seg1.prod(-infty<ll>, x + 1, x + y - t, infty<ll>));
    chmax(best, seg2.prod(x, infty<ll>, -infty<ll>, x - y + t + 1));
    if (best < 0) continue;
    best += v;
    chmax(ANS, best);
    seg1.multiply(a, a + b - c, best);
    seg2.multiply(a, a - b + c, best);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
