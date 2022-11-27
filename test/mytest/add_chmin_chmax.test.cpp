#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "alg/monoid/add_chmin_chmax.hpp"

void test() {
  int N = RNG(1, 100);
  vc<int> X(N);
  FOR(i, N) X[i] = RNG(-100, 100);
  vc<int> Y = X;
  int Q = RNG(0, 10);
  using Mono = Monoid_Add_Chmin_Chmax<int>;
  using F = typename Mono::value_type;
  F f = Mono::unit();

  FOR(Q) {
    int t = RNG(0, 3);
    int a = RNG(-100, 100);
    if (t == 0) {
      FOR(i, N) Y[i] += a;
      f = Mono::op(f, Mono::add(a));
    }
    if (t == 1) {
      FOR(i, N) chmin(Y[i], a);
      f = Mono::op(f, Mono::chmin(a));
    }
    if (t == 2) {
      FOR(i, N) chmax(Y[i], a);
      f = Mono::op(f, Mono::chmax(a));
    }
  }
  FOR(i, N) assert(Y[i] == Mono::eval(f, X[i]));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  FOR(100) test();
  solve();

  return 0;
}