#pragma once

#include "setfunc/ranked_zeta.hpp"

template <typename T, int LIM = 20>
vc<T> subset_convolution_square(const vc<T>& A) {
  auto RA = ranked_zeta<T, LIM>(A);
  int n = topbit(len(RA));
  FOR(s, len(RA)) {
    auto& f = RA[s];
    FOR_R(d, n + 1) {
      T x = 0;
      FOR(i, d + 1) x += f[i] * f[d - i];
      f[d] = x;
    }
  }
  return ranked_mobius<T, LIM>(RA);
}

template <typename T, int LIM = 20>
vc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {
  if (A == B) return subset_convolution_square(A);
  auto RA = ranked_zeta<T, LIM>(A);
  auto RB = ranked_zeta<T, LIM>(B);
  int n = topbit(len(RA));
  FOR(s, len(RA)) {
    auto &f = RA[s], g = RB[s];
    FOR_R(d, n + 1) {
      T x = 0;
      FOR(i, d + 1) x += f[i] * g[d - i];
      f[d] = x;
    }
  }
  return ranked_mobius<T, LIM>(RA);
}
