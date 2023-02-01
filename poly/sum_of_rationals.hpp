#pragma once

#include "poly/convolution.hpp"

// 有理式の和を計算する。分割統治 O(Nlog^2N)。N は次数の和。
template <typename mint>
pair<vc<mint>, vc<mint>> sum_of_rationals(vc<pair<vc<mint>, vc<mint>>> dat) {
  if (len(dat) == 0) {
    vc<mint> f = {0}, g = {1};
    return {f, g};
  }
  using P = pair<vc<mint>, vc<mint>>;
  auto add = [&](P& a, P& b) -> P {
    int na = len(a.fi) - 1, da = len(a.se) - 1;
    int nb = len(b.fi) - 1, db = len(b.se) - 1;
    int n = max(na + db, da + nb);
    vc<mint> num(n + 1);
    {
      auto f = convolution(a.fi, b.se);
      FOR(i, len(f)) num[i] += f[i];
    }
    {
      auto f = convolution(a.se, b.fi);
      FOR(i, len(f)) num[i] += f[i];
    }
    auto den = convolution(a.se, b.se);
    return {num, den};
  };

  while (len(dat) > 1) {
    int n = len(dat);
    FOR(i, 1, n, 2) { dat[i - 1] = add(dat[i - 1], dat[i]); }
    FOR(i, ceil(n, 2)) dat[i] = dat[2 * i];
    dat.resize(ceil(n, 2));
  }
  return dat[0];
}