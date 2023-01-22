#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "ds/offline_query/rectangle_add_point_sum.hpp"
#include "mod/modint.hpp"

using mint = modint998;
using QT = tuple<ll, ll, ll, ll, ll>;

pair<vc<QT>, vc<pi>> gen(int H, int W, int Q) {
  vc<tuple<ll, ll, ll, ll, ll>> add_query;
  FOR(Q) {
    ll a = RNG(0, H);
    ll b = RNG(a + 1, H + 1);
    ll c = RNG(0, W);
    ll d = RNG(c + 1, W + 1);
    ll x = RNG(0, mint::get_mod());
    add_query.eb(a, b, c, d, x);
  }

  vc<pi> sum_query;
  FOR(Q) {
    ll x = RNG(0, H), y = RNG(0, W);
    sum_query.eb(x, y);
  }
  return {add_query, sum_query};
}

vc<mint> sol_1(int H, int W, vc<QT> add_query, vc<pi> sum_query) {
  vv(mint, A, H, W);
  for (auto&& [a, b, c, d, x]: add_query) {
    FOR(i, a, b) FOR(j, c, d) { A[i][j] += mint(x); }
  }
  vc<mint> ANS;
  for (auto&& [x, y]: sum_query) ANS.eb(A[x][y]);
  return ANS;
}

vc<mint> sol_2(int H, int W, vc<QT> add_query, vc<pi> sum_query) {
  vc<mint> ANS;
  for (auto&& [x, y]: sum_query) {
    mint ans = 0;
    for (auto&& [a, b, c, d, v]: add_query) {
      if (a <= x && x < b && c <= y && y < d) ans += mint(v);
    }
    ANS.eb(ans);
  }
  return ANS;
}

void test() {
  FOR(H, 1, 10) FOR(W, 1, 10) FOR(Q, 10) {
    auto [add_query, sum_query] = gen(H, W, Q);
    Rectangle_Add_Point_Sum<Monoid_Add<mint>, int, 0> X;
    for (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);
    for (auto&& [a, b]: sum_query) X.sum_query(a, b);
    assert(X.calc() == sol_1(H, W, add_query, sum_query));
  }
  FOR(H, 1, 10) FOR(W, 1, 10) FOR(Q, 10) {
    auto [add_query, sum_query] = gen(H, W, Q);
    Rectangle_Add_Point_Sum<Monoid_Add<mint>, int, 1> X;
    for (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);
    for (auto&& [a, b]: sum_query) X.sum_query(a, b);
    assert(X.calc() == sol_1(H, W, add_query, sum_query));
  }
  FOR(10) {
    int H = RNG(1, 1'000'000'000);
    int W = RNG(1, 1'000'000'000);
    int Q = 100;
    auto [add_query, sum_query] = gen(H, W, Q);
    Rectangle_Add_Point_Sum<Monoid_Add<mint>, int, 0> X;
    for (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);
    for (auto&& [a, b]: sum_query) X.sum_query(a, b);
    assert(X.calc() == sol_2(H, W, add_query, sum_query));
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
