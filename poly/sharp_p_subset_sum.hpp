#include "poly/fps_exp.hpp"
template<typename mint>
vc<mint> sharp_p_subset_sum(vc<int> S, int LIM) {
  auto CNT = bincount(S, LIM);
  vc<mint> logf(LIM);
  FOR3(x, 1, LIM) {
    FOR3(d, 1, (LIM-1) / x + 1) {
      if (d & 1)
        logf[d * x] += mint(CNT[x]) * inv<mint>(d);
      else
        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);
    }
  }
  return fps_exp(logf);
}
