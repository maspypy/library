#pragma once
#include "poly/online/online_division.hpp"

template <typename mint>
struct Online_Log {
  vc<mint> f;
  Online_Division<mint> X;

  mint query(int i, mint f_i) {
    f.eb(f_i);
    if (i == 0) {
      assert(f_i == mint(1));
      return mint(0);
    }
    return inv<mint>(i) * X.query(i - 1, mint(i) * f_i, f[i - 1]);
  }
};
