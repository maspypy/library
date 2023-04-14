#define PROBLEM "https://atcoder.jp/contests/abc200/tasks/abc200_f"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "alg/monoid_pow.hpp"

using mint = modint107;

using P = pair<mint, mint>;
using ARR = array<array<P, 2>, 2>;

struct Mono {
  using value_type = ARR;
  using X = value_type;
  static X op(X x, X y) {
    if (x == unit()) return y;
    if (y == unit()) return x;
    X z = unit();
    FOR(i, 2) FOR(j, 2) z[i][j] = {mint(0), mint(0)};
    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d, 2) {
      auto& dp1 = x[a][b];
      auto& dp2 = y[c][d];
      z[a][d].fi += dp1.fi * dp2.fi;
      z[a][d].se += dp1.fi * dp2.se + dp2.fi * dp1.se;
      if (b != c) z[a][b].se += dp1.fi * dp2.fi;
    }
    return z;
  }
  static X unit() {
    X x;
    FOR(i, 2) FOR(j, 2) x[i][j] = {mint(0), mint(0)};
    return x;
  }
  static X from_element(char c) {
    X t = unit();
    FOR(x, 2) {
      if (x == 0 && c == '1') continue;
      if (x == 1 && c == '0') continue;
      t[x][x] = {1, 0};
    }
    return t;
  }
  static constexpr bool commute = 0;
};

void solve() {
  STR(S);
  INT(K);
  ARR x = Mono::unit();
  for (auto&& c: S) x = Mono::op(x, Mono::from_element(c));

  ARR e = monoid_pow<Mono>(x, K);
  mint ANS = 0;
  FOR(a, 2) FOR(b, 2) {
    auto [cnt, sm] = e[a][b];
    if (a != b) ANS += (sm + cnt) * inv<mint>(2);
    if (a == b) ANS += sm * inv<mint>(2);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
