#define PROBLEM "https://yukicoder.me/problems/no/1411"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/lpf_table.hpp"
#include "nt/factor.hpp"

using mint = modint107;

void solve() {
  LL(N);
  const int LIM = 1'000'000;
  auto lpf = lpf_table(LIM);

  vvc<pair<ll, int>> F(N);

  vc<pair<int, int>> MAX2(LIM);
  auto add = [&](int p, int e) -> void {
    if (MAX2[p].fi < e) { MAX2[p] = mp(e, MAX2[p].fi); }
    elif (MAX2[p].se < e) { MAX2[p].se = e; }
  };

  mint prod = 1;
  mint lcm = 1;

  VEC(int, A, N);
  FOR(i, N) {
    prod *= mint(A[i]);
    F[i] = factor_by_lpf(A[i], lpf);
    for (auto&& [p, e]: F[i]) { add(p, e); }
  }

  FOR(p, LIM) if (MAX2[p].fi) lcm *= mint(p).pow(MAX2[p].fi);

  FOR(i, N) {
    mint a = prod * inv<mint>(A[i]);
    mint b = lcm;
    for (auto&& [p, e]: F[i]) {
      auto& [mx, mx2] = MAX2[p];
      int m = (e == mx ? mx2 : mx);
      if (e > m) b *= inv<mint>(p).pow(e - m);
    }
    print(a - b);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
