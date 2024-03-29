#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwicktree/fenwicktree_2d.hpp"
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

  vi X1(N), Y1(N), X2(N), Y2(N);
  FOR(i, N) {
    auto [t, x, y, v] = dat[i];
    X1[i] = x;
    X2[i] = -x;
    Y1[i] = t - x - y;
    Y2[i] = x - y + t;
  }
  FenwickTree_2D<Mono, ll, false> seg1(X1, Y1);
  FenwickTree_2D<Mono, ll, false> seg2(X2, Y2);

  ll ANS = 0;
  FOR(i, N) {
    const auto [t, x, y, v] = dat[i];
    const ll a = x, b = y, c = t;
    if (i == 0) {
      seg1.add(a, c - a - b, 0);
      seg2.add(-a, a - b + c, 0);
      continue;
    }
    ll best = -infty<ll>;
    chmax(best, seg1.prefix_sum(x + 1, t - x - y + 1));
    chmax(best, seg2.prefix_sum((-x) + 1, x - y + t + 1));
    if (best < 0) continue;
    best += v;
    chmax(ANS, best);
    seg1.add(a, c - a - b, best);
    seg2.add(-a, a - b + c, best);
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
