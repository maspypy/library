#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/ceil_range.hpp"
#include "enumerate/floor_range.hpp"

void test_floor() {
  ll LIM = 1000;
  using T = tuple<ll, ll, ll>;
  auto F = [&](ll N) -> vc<T> {
    vc<T> dat;
    auto f = [&](ll q, ll l, ll r) -> void { dat.eb(q, l, r); };
    floor_range<ll>(N, f);
    return dat;
  };
  auto G = [&](ll N) -> vc<T> {
    vvc<ll> tmp(N + 1);
    FOR(x, 1, LIM) tmp[floor(N, x)].eb(x);
    vc<T> dat;
    FOR(x, 1, N + 1) {
      if (len(tmp[x])) {
        ll lo = tmp[x][0];
        ll hi = tmp[x].back();
        dat.eb(x, lo, hi + 1);
      }
    }
    return dat;
  };
  FOR(N, 1, 100) { assert(F(N) == G(N)); }
}

void test_ceil() {
  ll LIM = 1000;
  using T = tuple<ll, ll, ll>;
  auto F = [&](ll N) -> vc<T> {
    vc<T> dat;
    auto f = [&](ll q, ll l, ll r) -> void { dat.eb(q, l, r); };
    ceil_range<ll>(N, f, LIM);
    return dat;
  };
  auto G = [&](ll N) -> vc<T> {
    vvc<ll> tmp(N + 1);
    FOR(x, 1, LIM) tmp[ceil(N, x)].eb(x);
    vc<T> dat;
    FOR(x, 1, N + 1) {
      if (len(tmp[x])) {
        ll lo = tmp[x][0];
        ll hi = tmp[x].back();
        dat.eb(x, lo, hi + 1);
      }
    }
    return dat;
  };
  FOR(N, 1, 100) { assert(F(N) == G(N)); }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_floor();
  test_ceil();
  solve();

  return 0;
}
