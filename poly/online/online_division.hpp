#pragma once
#include "poly/online/online_convolution.hpp"

// query(i)：a[i], b[i] を与えて (f/g)[i] を得る。
// g[0] == 1 を仮定する
template <typename mint>
struct Online_Division {
  vc<mint> f, g, F;
  Online_Convolution<mint> X;

  mint query(int i, mint f_i, mint g_i) {
    assert(i == len(f));
    f.eb(f_i);
    g.eb(g_i);
    if (i == 0) {
      assert(g_i == mint(1));
      F.eb(f_i);
      return F[0];
    }
    F.eb(f[i] - X.query(i - 1, F[i - 1], g[i]));
    return F[i];
  }
};