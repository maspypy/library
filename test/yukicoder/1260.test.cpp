#define PROBLEM "https://yukicoder.me/problems/no/1260"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/integer_kth_root.hpp"
#include "other/floor_range.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  mint ANS = 0;
  ll LIM = integer_kth_root(2, N) + 1;
  auto f = [&](ll i) -> ll {
    ll res = 0;
    ll n = N;
    while (n) {
      res += n % i;
      n /= i;
    }
    return res;
  };
  FOR(i, 2, LIM) {
    if (i <= N) ANS += mint(f(i));
  }

  floor_range(q, l, r, N) {
    ll lo = max(l, LIM);
    ll hi = r;
    if (lo >= hi) continue;
    ANS += mint(q) * mint(hi - lo);
    ANS += mint(N) * mint(hi - lo)
           - mint(q) * mint(lo + hi - 1) * mint(hi - lo) * inv<mint>(2);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
