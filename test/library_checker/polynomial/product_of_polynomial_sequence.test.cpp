#pragma once

#include "poly/convolution.hpp"

template <typename T>
vc<T> convolution_all(vc<vc<T>>& polys) {
  if (len(polys) == 0) return {T(1)};
  while (1) {
    int n = len(polys);
    if (n == 1) break;
    int m = ceil(n, 2);
    FOR(i, m) {
      if (2 * i + 1 == n) {
        polys[i] = polys[2 * i];
      } else {
        polys[i] = convolution(polys[2 * i], polys[2 * i + 1]);
      }
    }
    polys.resize(m);
  }
  return polys[0];
}
