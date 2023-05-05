#include "setfunc/subset_convolution.hpp"

// for fixed sps s, consider linear map F:a->b = subset-conv(a,s)
// given x, calculate transpose(F)(x)
template <typename mint, int LIM>
vc<mint> transposed_subset_convolution(int N, vc<mint> s, vc<mint> x) {
  /*
  sum_{j}x_jb_j = sum_{i subset j}x_ja_is_{j-i} = sum_{i}y_ia_i.
  y_i = sum_{j supset i}x_js_{j-i}
  (rev y)_i = sum_{j subset i}(rev x)_js_{i-j}
  y = rev(conv(rev x), s)
  */
  reverse(all(x));
  x = subset_convolution<mint, LIM>(x, s);
  reverse(all(x));
  return x;
}

// for fixed sps s s.t. s[0] == 0.
// consider linear map F:f->t=f(s) for egf f.
// given x, calcuate transpose(F)(x)
// equivalent: calculate sum_i x_i(s^k/k!)_i for k=0,1,...,N
template <typename mint, int LIM>
vc<mint> transposed_sps_composition_egf(int N, vc<mint>& s, vc<mint> x) {
  assert(len(s) == (1 << N) && len(x) == (1 << N) && s[0] == mint(0));
  vc<mint> y(N + 1);
  y[0] = x[0];
  auto& dp = x;
  FOR(i, N) {
    vc<mint> newdp(1 << (N - 1 - i));
    FOR(j, N - i) {
      vc<mint> a = {s.begin() + (1 << j), s.begin() + (2 << j)};
      vc<mint> b = {dp.begin() + (1 << j), dp.begin() + (2 << j)};
      b = transposed_subset_convolution<mint, LIM>(j, a, b);
      FOR(k, len(b)) newdp[k] += b[k];
    }
    swap(dp, newdp);
    y[1 + i] = dp[0];
  }
  return y;
}
