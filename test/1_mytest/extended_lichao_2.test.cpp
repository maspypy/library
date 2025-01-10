#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "my_template.hpp"

#include "convex/extended_lichao_2.hpp"
#include "random/base.hpp"
#include "random/shuffle.hpp"

void test_minimize() {
  ll N = RNG(1, 100);
  vi X(201);
  FOR(i, 201) X[i] = i - 100;
  shuffle(X);
  X.resize(N);

  Extended_LiChao_Tree_2<true> LCT(X);
  vi A(N, infty<ll>);

  ll Q = 100;
  FOR(Q) {
    ll t = RNG(0, 3);
    ll L = RNG(-100, 101);
    ll R = RNG(-100, 101);
    if (L > R) swap(L, R);
    ++R;
    ll a = RNG(-10, 10);
    ll b = RNG(-100, 100);
    if (t == 0) {
      // line
      LCT.chmin_line(a, b);
      FOR(i, N) chmin(A[i], a * X[i] + b);
    }
    if (t == 1) {
      // segment
      LCT.chmin_segment(L, R, a, b);
      FOR(i, N) {
        if (L <= X[i] && X[i] < R) chmin(A[i], a * X[i] + b);
      }
    }
    if (t == 2) {
      // apply
      LCT.add_segment(L, R, b);
      FOR(i, N) {
        if (L <= X[i] && X[i] < R && A[i] < infty<ll>) A[i] += b;
      }
    }
    ll god = infty<ll>;
    FOR(i, N) {
      if (L <= X[i] && X[i] < R) chmin(god, A[i]);
    }
    ll ans = LCT.query(L, R);
    assert(god == ans);
  }
}

void test_maximize() {
  ll N = RNG(1, 100);
  vi X(201);
  FOR(i, 201) X[i] = i - 100;
  shuffle(X);
  X.resize(N);

  Extended_LiChao_Tree_2<false> LCT(X);
  vi A(N, -infty<ll>);

  ll Q = 100;
  FOR(Q) {
    ll t = RNG(0, 3);
    ll L = RNG(-100, 101);
    ll R = RNG(-100, 101);
    if (L > R) swap(L, R);
    ++R;
    ll a = RNG(-10, 10);
    ll b = RNG(-100, 100);
    if (t == 0) {
      // line
      LCT.chmax_line(a, b);
      FOR(i, N) chmax(A[i], a * X[i] + b);
    }
    if (t == 1) {
      // segment
      LCT.chmax_segment(L, R, a, b);
      FOR(i, N) {
        if (L <= X[i] && X[i] < R) chmax(A[i], a * X[i] + b);
      }
    }
    if (t == 2) {
      // apply
      LCT.add_segment(L, R, b);
      FOR(i, N) {
        if (L <= X[i] && X[i] < R && A[i] > -infty<ll>) A[i] += b;
      }
    }
    ll god = -infty<ll>;
    FOR(i, N) {
      if (L <= X[i] && X[i] < R) chmax(god, A[i]);
    }
    ll ans = LCT.query(L, R);
    assert(god == ans);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(10000) test_minimize();
  FOR(10000) test_maximize();
  solve();
  return 0;
}
