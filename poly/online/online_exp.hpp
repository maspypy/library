#pragma once
#include "poly/online/online_convolution.hpp"

// query(i)：f[i] を与えて (f^{-1})[i] を得る。
template <typename mint>
struct Online_Exp {
  vc<mint> F;
  Online_Convolution<mint> X;

  mint query(int i, mint f_i) {
    if (i == 0) {
      assert(f_i == mint(0));
      F.eb(mint(1));
      return mint(1);
    }
    mint x = inv<mint>(i) * X.query(i - 1, F[i - 1], f_i * mint(i));
    F.eb(x);
    return x;
  }
};