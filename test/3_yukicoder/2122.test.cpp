#define PROBLEM "https://yukicoder.me/problems/no/2122"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/functional.hpp"
#include "mod/modint.hpp"
#include "poly/coef_of_rational_fps.hpp"

using mint = modint<10000>;

ll to(ll n, ll M) {
  vc<mint> f = {0, 1};
  vc<mint> g = {1, -n, -1};
  mint x = coef_of_rational_fps(f, g, M);
  if (M % 2 == 1) { x -= mint(1); }
  return x.val;
}

void test() {
  using Re = long double;
  FOR(n, 10) {
    Re sqD = sqrt(n * n + 4);
    Re a = (n + sqD) / 2;
    FOR(M, 7) {
      Re x = 1.0;
      FOR(M) x *= a;
      x /= sqD;
      int v = floor(x);
      v %= 10000;
      assert(v == to(n, M));
    }
  }
}

void solve() {
  test();
  STR(S);
  LL(M);
  LL(L);

  auto out = [&](ll x) -> void {
    string s = to_string(x);
    while (len(s) < 4) s = "0" + s;
    return print(s);
  };

  ll N = 10000;
  FunctionalGraph<bool> X(N);
  FOR(n, N) {
    ll m = to(n, M);
    X.add(n, m);
  }

  ll a = stoi(S);

  auto [G, tree] = X.build();
  ll ANS = X.jump(tree, a, L);
  out(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
