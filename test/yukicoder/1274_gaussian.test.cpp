#define PROBLEM "https://yukicoder.me/problems/no/1274"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/gaussian_integers.hpp"

void solve() {
  using G = Gaussian_Integer<i128>;
  LL(a, b);
  if (a == 0 && b == 0) return print(0.25);
  G g = G::gcd(G(a, b), G(b, a));

  using Re = long double;
  ll LIM = 100;
  vc<Re> f(LIM);
  FOR(x, 1, LIM) {
    Re a = Re(1) / x;
    Re p = 1.0;
    FOR(x) p *= a;
    f[x] = p;
  }

  Re ANS = 0;
  FOR(x, 1, LIM) FOR(y, 1, LIM - x) {
    if (x + y >= LIM) continue;
    G p(x - 1, y - 1);
    p %= g;
    if (p.x == 0 && p.y == 0) { ANS += f[x + y]; }
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
