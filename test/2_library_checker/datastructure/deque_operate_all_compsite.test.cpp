#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "alg/monoid/affine.hpp"
#include "ds/sliding_window_aggregation.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  using G = Monoid_Affine<mint>;
  SWAG_deque<G> X;
  FOR(Q) {
    LL(t);
    if (t == 0) {
      INT(a, b);
      X.push_front({a, b});
    }
    if (t == 1) {
      INT(a, b);
      X.push_back({a, b});
    }
    if (t == 2) { X.pop_front(); }
    if (t == 3) { X.pop_back(); }
    if (t == 4) {
      INT(x);
      auto f = X.prod();
      print(G::eval(f, x));
    }
  }
}

signed main() {
  solve();
  return 0;
}
