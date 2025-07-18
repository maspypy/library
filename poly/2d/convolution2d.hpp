#pragma once

#include "poly/convolution.hpp"

template <typename T>
vc<vc<T>> convolution2d(vc<vc<T>>& f, vc<vc<T>>& g, bool truncate = false) {
  auto shape = [&](vc<vc<T>>& f) -> pi {
    ll H = len(f);
    ll W = (H == 0 ? 0 : len(f[0]));
    return {H, W};
  };
  auto [H1, W1] = shape(f);
  auto [H2, W2] = shape(g);
  ll H = H1 + H2 - 1;
  ll W = W1 + W2 - 1;

  vc<T> ff(H1 * W);
  vc<T> gg(H2 * W);
  FOR(x, H1) FOR(y, W1) ff[W * x + y] = f[x][y];
  FOR(x, H2) FOR(y, W2) gg[W * x + y] = g[x][y];
  auto hh = convolution(ff, gg);
  int N = H, M = W;
  if (truncate) {
    assert(H1 == H2 && W1 == W2);
    N = H1, M = W1;
  }
  vc<vc<T>> h(N, vc<T>(M));
  FOR(x, N) FOR(y, M) h[x][y] = hh[W * x + y];
  return h;
}
