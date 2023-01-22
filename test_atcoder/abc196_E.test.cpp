#define PROBLEM "https://atcoder.jp/contests/abc196/tasks/abc196_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add_chmin_chmax.hpp"

void solve() {
  using Mono = Monoid_Add_Chmin_Chmax<ll>;
  using F = typename Mono::value_type;
  F f = Mono::unit();

  LL(N);
  FOR(N) {
    LL(a, t);
    if (t == 1) f = Mono::op(f, Mono::add(a));
    if (t == 2) f = Mono::op(f, Mono::chmax(a));
    if (t == 3) f = Mono::op(f, Mono::chmin(a));
  }

  LL(Q);
  FOR(Q) {
    LL(x);
    print(Mono::eval(f, x));
  }
}

signed main() {
  solve();

  return 0;
}