#pragma once
#include "random/base.hpp"

// A[i1][j1] + A[i2][j2] <= A[i1][j2] + A[i2][j1] for i1 < i2, j1 < j2.
vvc<ll> random_monge_matrix(int H, int W) {
  ll LIM = 10;
  vv(ll, D, H, W);
  FOR(i, H) FOR(j, W) D[i][j] = RNG(0, LIM + 1);

  vv(ll, A, H, W);
  FOR(i, H) FOR(j, W) {
    ll x = D[i][j];
    if (i) x += A[i - 1][j];
    if (j) x += A[i][j - 1];
    if (i && j) x -= A[i - 1][j - 1];
    A[i][j] = x;
  }

  vc<ll> row(H), col(W);
  FOR(i, H) row[i] = RNG(-LIM * W, LIM * W + 1);
  FOR(j, W) col[j] = RNG(-LIM * H, LIM * H + 1);

  FOR(i, H) FOR(j, W) A[i][j] = -A[i][j] + row[i] + col[j];
  return A;
}