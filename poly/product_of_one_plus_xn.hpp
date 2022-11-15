#include "poly/fps_exp.hpp"

// prod (1 + x^a) を x^{LIM} まで求める
template <typename mint, typename INT>
vc<mint> product_of_one_plus_xn(vc<INT> A, int LIM) {
  vc<int> CNT(LIM + 1);
  for (auto&& x: A) {
    if (x <= LIM) CNT[x]++;
  }

  vc<mint> logf(LIM + 1);
  FOR3(x, 1, LIM + 1) {
    FOR3(d, 1, LIM / x + 1) {
      if (d & 1)
        logf[d * x] += mint(CNT[x]) * inv<mint>(d);
      else
        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);
    }
  }
  auto f = fps_exp(logf);
  mint c = mint(2).pow(CNT[0]);
  for (auto&& x: f) x *= c;
  return f;
}