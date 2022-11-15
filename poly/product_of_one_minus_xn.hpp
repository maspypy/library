#include "poly/fps_exp.hpp"

// prod (1 - x^a) を x^{LIM} まで求める
template <typename mint, typename INT>
vc<mint> product_of_one_minus_xn(vc<INT> A, int LIM) {
  vc<int> CNT(LIM + 1);
  for (auto&& x: A) {
    if (x <= LIM) CNT[x]++;
  }
  if (CNT[0]) { return vc<mint>(LIM + 1); }

  vc<mint> logf(LIM + 1);
  FOR(x, 1, LIM + 1) {
    FOR(d, 1, LIM / x + 1) { logf[d * x] -= mint(CNT[x]) * inv<mint>(d); }
  }
  return fps_exp(logf);
}
