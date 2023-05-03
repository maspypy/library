#include "setfunc/subset_convolution.hpp"

// sum_i f_i/i! s^i, s^i is subset-convolution
template <typename mint, int LIM>
vc<mint> sps_exp(int N, vc<mint>& s) {
  assert(len(s) == (1 << N) && s[0] == mint(0));
  vc<mint> dp(1 << N);
  dp[0] = mint(1);
  FOR(i, N) {
    vc<mint> a = {s.begin() + (1 << i), s.begin() + (2 << i)};
    vc<mint> b = {dp.begin(), dp.begin() + (1 << i)};
    a = subset_convolution<mint, LIM>(a, b);
    copy(all(a), dp.begin() + (1 << i));
  }
  return dp;
}
