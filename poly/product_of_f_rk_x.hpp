#pragma once

#include "poly/fps_log.hpp"
#include "poly/fps_exp.hpp"

// とりあえず dense のみ、exp, log で O(NlogN)
// f(x)f(rx)...f(r^{M-1}x)
template <typename mint>
vc<mint> product_of_f_rk_x(vc<mint>& f, mint r, ll M) {
  assert(f[0] == mint(1));

  mint pow_r = mint(1);
  mint rm = r.pow(M);
  mint pow_rm = mint(1);

  vc<mint> g = fps_log(f);
  FOR(i, 1, len(g)) {
    pow_r *= r;
    pow_rm *= rm;
    if (pow_r == mint(1)) {
      g[i] *= mint(M);
    } else {
      g[i] *= (pow_rm - mint(1)) / (pow_r - mint(1));
    }
  }
  return fps_exp(g);
}
