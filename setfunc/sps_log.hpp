#include "mod/modint.hpp"
#include "setfunc/sps_composition.hpp"

// exp の逆手順で計算する
template <typename mint, int LIM>
vc<mint> sps_log(vc<mint>& dp) {
  const int N = topbit(len(dp));
  assert(len(dp) == (1 << N) && dp[0] == mint(1));
  vc<mint> s(1 << N);
  FOR_R(i, N) {
    vc<mint> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};
    vc<mint> b = {dp.begin(), dp.begin() + (1 << i)};
    auto RA = ranked_zeta<mint, LIM>(a);
    auto RB = ranked_zeta<mint, LIM>(b);
    FOR(s, 1 << i) {
      auto &f = RA[s], &g = RB[s];
      // assert(g[0] == mint(1));
      FOR(d, i + 1) { FOR(i, d) f[d] -= f[i] * g[d - i]; }
    }
    a = ranked_mobius<mint, LIM>(RA);
    copy(all(a), s.begin() + (1 << i));
  }
  return s;
}