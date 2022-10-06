#define PROBLEM "https://yukicoder.me/problems/no/1411"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/lpf_table.hpp"
#include "nt/factor.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  const int LIM = 1'000'000;
  auto lpf = lpf_table(LIM);

  vvc<pair<int, int>> DAT(LIM);
  FOR(i, N) {
    for (auto&& [p, e]: factor_by_lpf(A[i], lpf)) { DAT[p].eb(e, i); }
  }

  vc<mint> PROD(N, mint(1)), LCM(N, mint(1));
  mint prod = 1;
  mint lcm = 1;

  for (auto&& p: primetable(LIM)) {
    auto& dat = DAT[p];
    if (len(dat) == 0) continue;

    int sm = 0;
    int mx = 0, mx2 = 0;
    for (auto&& [e, i]: dat) {
      sm += e;
      if (mx < e) { tie(mx, mx2) = mp(e, mx); }
      elif (mx2 < e) { mx2 = e; }
    }

    prod *= mint(p).pow(sm);
    for (auto&& [e, i]: dat) { PROD[i] *= inv<mint>(p).pow(e); }

    lcm *= mint(p).pow(mx);
    for (auto&& [e, i]: dat) {
      int m = (e == mx ? mx2 : mx);
      if (m < mx) LCM[i] *= inv<mint>(p).pow(mx - m);
    }
  }

  for (auto&& x: PROD) x *= prod;
  for (auto&& x: LCM) x *= lcm;

  FOR(i, N) print(PROD[i] - LCM[i]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
