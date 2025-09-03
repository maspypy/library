#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/beats_kinetic.hpp"
#include "random/base.hpp"

void test_mi() {
  FOR(N, 1, 100) {
    vi X(N), Y(N);
    FOR(i, N) X[i] = RNG(-100, 100);
    FOR(i, N) Y[i] = RNG(-100, 100);
    Beats_Kinetic_Min<ll, ll> seg(N, [&](int i) -> pair<int, int> { return {X[i], Y[i]}; });
    ll Q = 100;
    FOR(Q) {
      ll t = RNG(0, 3);
      ll i = RNG(0, N);
      ll L = RNG(0, N);
      ll R = RNG(L, N + 1);
      ll a = RNG(-100, 100);
      ll b = RNG(-100, 100);
      if (t == 0) {
        // set
        seg.set(i, a, b);
        X[i] = a, Y[i] = b;
      }
      if (t == 1) {
        // apply
        a = abs(a);
        seg.apply(L, R, a, b);
        FOR(i, L, R) Y[i] += a * X[i] + b;
      }
      if (t == 2) {
        // prod
        ll mi = infty<ll>;
        FOR(i, L, R) chmin(mi, Y[i]);
        auto [idx, x, y] = seg.prod(L, R);
        assert(mi == y);
      }
    }
  }
}

void test_ma() {
  FOR(N, 1, 100) {
    vi X(N), Y(N);
    FOR(i, N) X[i] = RNG(-100, 100);
    FOR(i, N) Y[i] = RNG(-100, 100);
    Beats_Kinetic_Max<ll, ll> seg(N, [&](int i) -> pair<int, int> { return {X[i], Y[i]}; });
    ll Q = 100;
    FOR(Q) {
      ll t = RNG(0, 3);
      ll i = RNG(0, N);
      ll L = RNG(0, N);
      ll R = RNG(L, N + 1);
      ll a = RNG(-100, 100);
      ll b = RNG(-100, 100);
      if (t == 0) {
        // set
        seg.set(i, a, b);
        X[i] = a, Y[i] = b;
      }
      if (t == 1) {
        // apply
        a = abs(a);
        seg.apply(L, R, a, b);
        FOR(i, L, R) Y[i] += a * X[i] + b;
      }
      if (t == 2) {
        // prod
        ll ma = -infty<ll>;
        FOR(i, L, R) chmax(ma, Y[i]);
        auto [idx, x, y] = seg.prod(L, R);
        assert(ma == y);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(100) {
    test_mi();
    test_ma();
  }
  solve();
  return 0;
}