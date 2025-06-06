#pragma once
#include "setfunc/ranked_zeta.hpp"

// sum_i f_i/i! s^i, s^i is subset-convolution
template <typename mint, int LIM>
vc<mint> sps_composition_egf(vc<mint>& f, vc<mint>& s) {
  const int N = topbit(len(s));
  assert(len(s) == (1 << N) && s[0] == mint(0));
  if (len(f) > N) f.resize(N + 1);
  int D = len(f) - 1;
  using ARR = array<mint, LIM + 1>;
  vvc<ARR> zs(N);
  FOR(i, N) { zs[i] = ranked_zeta<mint, LIM>({s.begin() + (1 << i), s.begin() + (2 << i)}); }

  // dp : (d/dt)^df(s) (d=D,D-1,...)
  vc<mint> dp(1 << (N - D));
  dp[0] = f[D];
  FOR_R(d, D) {
    vc<mint> newdp(1 << (N - d));
    newdp[0] = f[d];
    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);
    FOR(i, N - d) {
      // zs[1<<i:2<<i], zdp[0:1<<i]
      vc<ARR> znewdp(1 << i);
      FOR(k, 1 << i) {
        FOR(p, i + 1) FOR(q, i - p + 1) { znewdp[k][p + q] += zdp[k][p] * zs[i][k][q]; }
      }
      auto x = ranked_mobius<mint, LIM>(znewdp);
      copy(all(x), newdp.begin() + (1 << i));
    }
    swap(dp, newdp);
  }
  return dp;
}

// sum_i f_i s^i, s^i is subset-convolution
template <typename mint, int LIM>
vc<mint> sps_composition_poly(vc<mint> f, vc<mint> s) {
  const int N = topbit(len(s));
  assert(len(s) == (1 << N));
  if (f.empty()) return vc<mint>(1 << N, mint(0));
  // convert to egf problem
  int D = min<int>(len(f) - 1, N);
  vc<mint> g(D + 1);
  mint c = s[0];
  s[0] = 0;
  // (x+c)^i
  vc<mint> pow(D + 1);
  pow[0] = 1;
  FOR(i, len(f)) {
    FOR(j, D + 1) g[j] += f[i] * pow[j];
    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ? mint(0) : pow[j - 1]);
  }
  // to egf
  mint factorial = 1;
  FOR(j, D + 1) g[j] *= factorial, factorial *= mint(j + 1);
  return sps_composition_egf<mint, LIM>(g, s);
}
