#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"

#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/gaussian_integers.hpp"

void solve() {
  LL(a, b, c, d);
  using G = Gaussian_Integer<ll>;
  G x(a, b);
  G y(c, d);
  G g = G::gcd(x, y);
  print(g.x, g.y);
}

signed main() {
  INT(T);
  FOR(T) solve();

  return 0;
}