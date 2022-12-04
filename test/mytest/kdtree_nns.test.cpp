#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "ds/kdtree/kdtree.hpp"

void test_random_points_nns_is_fast() {
  ll N = 100'000, Q = 100'000;
  vi X(N), Y(N);
  ll LIM = 1'000'000'000;
  FOR(i, N) X[i] = RNG(0, LIM);
  FOR(i, N) Y[i] = RNG(0, LIM);
  KDTree<ll> KDT(X, Y);
  FOR(Q) {
    ll x = RNG(0, LIM);
    ll y = RNG(0, LIM);
    KDT.nearest_neighbor_search(x, y);
  }
}

void test_nns_is_correct() {
  ll LIM = RNG(10, 1000);
  ll N = RNG(1, 100);
  ll Q = 1000;
  vi X(N), Y(N);
  FOR(i, N) X[i] = RNG(0, LIM);
  FOR(i, N) Y[i] = RNG(0, LIM);

  KDTree<ll> KDT(X, Y);
  FOR(Q) {
    ll x = RNG(0, LIM);
    ll y = RNG(0, LIM);
    ll min_d = 1'000'000'000;
    auto dist = [&](int i) -> ll {
      ll dx = X[i] - x, dy = Y[i] - y;
      return dx * dx + dy * dy;
    };
    FOR(i, N) chmin(min_d, dist(i));
    int k = KDT.nearest_neighbor_search(x, y);
    assert(min_d == dist(k));
  }
}

void test() {
  test_random_points_nns_is_fast();
  test_nns_is_correct();
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
