#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "random/base.hpp"
#include "convex/lattice_point_sum_polynomial.hpp"
#include "mod/modint.hpp"

using mint = modint998;

template <int K1, int K2>
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

  array<array<mint, K2 + 1>, K1 + 1> god{};
  auto add_point = [&](ll x, ll y) -> void {
    FOR(i, K1 + 1) FOR(j, K2 + 1) { god[i][j] += mint(x).pow(i) * mint(y).pow(j); }
  };

  FOR(x, -10, 11) {
    ll mi = -infty<ll>, ma = infty<ll>;
    for (auto& [a, b, c]: LINE) {
      if (b == 0) {
        // ax>=c
        if (a * x <= c) continue;
        mi = infty<ll> + 1;
        break;
      }
      if (b > 0) { chmin(ma, floor<ll>(c - a * x, b)); }
      if (b < 0) { chmax(mi, ceil<ll>(a * x - c, -b)); }
    }

    if (mi > ma) continue;
    if (mi == -infty<ll> || ma == infty<ll>) {
      FOR(i, K1 + 1) FOR(j, K2 + 1) god[i][j] = 0;
      break;
    }
    FOR(y, mi, ma + 1) add_point(x, y);
  }

  auto ANS = lattice_point_sum_polynomial<mint, K1, K2>(LINE);
  assert(god == ANS);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(1000) {
    test<0, 0>();
    test<0, 1>();
    test<0, 2>();
    test<0, 3>();
    test<1, 0>();
    test<1, 1>();
    test<1, 2>();
    test<1, 3>();
    test<2, 0>();
    test<2, 1>();
    test<2, 2>();
    test<2, 3>();
    test<3, 0>();
    test<3, 1>();
    test<3, 2>();
    test<3, 3>();
  }

  solve();

  return 0;
}