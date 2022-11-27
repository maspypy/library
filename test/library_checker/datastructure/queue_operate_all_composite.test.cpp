#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/affine.hpp"
#include "ds/swag.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(Q);
  using Mono = Monoid_Affine<mint>;
  using F = Mono::value_type;

  SWAG<Mono> swag;

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(a, b);
      swag.push(F({a, b}));
    }
    elif (t == 1) { swag.pop(); }
    elif (t == 2) {
      LL(x);
      F f = swag.prod();
      print(Mono::eval(f, x));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
