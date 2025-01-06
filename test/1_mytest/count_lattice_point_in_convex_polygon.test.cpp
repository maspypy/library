#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/base.hpp"
#include "convex/count_lattice_point_in_convex_polygon.hpp"

void test() {
  ll N = RNG(0, 7);
  vc<tuple<ll, ll, ll>> LINE;
  FOR(N) {
    while (1) {
      ll a = RNG(-3, 4);
      ll b = RNG(-3, 4);
      if (a == 0 && b == 0) continue;
      ll c = RNG(-30, 31);
      LINE.eb(a, b, c);
      break;
    }
  }
  ll L = RNG(-30, 31);
  ll R = RNG(-30, 31);
  if (L > R) swap(L, R);
  ++R;

  ll god = 0;
  FOR(x, L, R) {
    ll mi = -infty<ll>, ma = infty<ll>;
    for (auto& [a, b, c]: LINE) {
      if (b == 0) {
        // ax>=c
        if (a * x <= c) continue;
        mi = infty<ll> + 1;
        break;
      }
      if (b > 0) {
        // ax+by<=c
        // by<=c-ax
        chmin(ma, floor<ll>(c - a * x, b));
      }
      if (b < 0) { chmax(mi, ceil<ll>(a * x - c, -b)); }
    }

    if (mi > ma) continue;
    if (mi == -infty<ll> || ma == infty<ll>) {
      god = -1;
      break;
    }
    god += ma - mi + 1;
  }

  ll ANS = count_lattice_point_in_convex_polygon(L, R, LINE);
  assert(god == ANS);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(1000000) test();

  solve();

  return 0;
}