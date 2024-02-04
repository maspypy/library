#include "alg/monoid/add.hpp"

template <typename Monoid, typename XY, bool SMALL_X = false>
struct Dual_FenwickTree_2D {
  using G = Monoid;
  using E = typename G::value_type;
  static_assert(G::commute);
  int N;
  vc<XY> keyX;
  XY min_X;
  vc<int> indptr;
  vc<XY> keyY;
  vc<E> dat;

  Dual_FenwickTree_2D(vc<XY>& X, vc<XY>& Y) { build(X, Y); }

  inline int xtoi(XY x) {
    if constexpr (SMALL_X) {
      return clamp<int>(x - min_X, 0, N);
    } else {
      return LB(keyX, x);
    }
  }
  inline int nxt(int i) { return i + ((i + 1) & -(i + 1)); }
  inline int prev(int i) { return i - ((i + 1) & -(i + 1)); }

  void build(vc<XY> X, vc<XY> Y) {
    assert(len(X) == len(Y));
    if constexpr (!SMALL_X) {
      keyX = X;
      UNIQUE(keyX);
      N = len(keyX);
    } else {
      min_X = (len(X) == 0 ? 0 : MIN(X));
      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;
      keyX.resize(N);
      FOR(i, N) keyX[i] = min_X + i;
    }

    auto I = argsort(Y);
    X = rearrange(X, I), Y = rearrange(Y, I);

    FOR(i, len(X)) X[i] = xtoi(X[i]);

    vc<XY> last_y(N, -infty<XY> - 1);
    indptr.assign(N + 1, 0);
    FOR(i, len(X)) {
      int ix = X[i];
      XY y = Y[i];
      while (ix < N) {
        if (last_y[ix] == y) break;
        last_y[ix] = y, indptr[ix + 1]++, ix = nxt(ix);
      }
    }
    FOR(i, N) indptr[i + 1] += indptr[i];
    keyY.resize(indptr.back());
    dat.assign(indptr.back(), G::unit());
    fill(all(last_y), -infty<XY> - 1);
    vc<int> prog = indptr;
    FOR(i, len(X)) {
      int ix = X[i];
      XY y = Y[i];
      while (ix < N) {
        if (last_y[ix] == y) break;
        last_y[ix] = y, keyY[prog[ix]++] = y, ix = nxt(ix);
      }
    }
  }

  E get(XY x, XY y) {
    E val = G::unit();
    int i = xtoi(x);
    assert(keyX[i] == x);
    while (i < N) { val = G::op(val, get_i(i, y)), i = nxt(i); }
    return val;
  }

  void apply(XY lx, XY rx, XY ly, XY ry, E val) {
    int L = xtoi(lx) - 1, R = xtoi(rx) - 1;
    E neg = G::inverse(val);
    while (L < R) { apply_i(R, ly, ry, val), R = prev(R); }
    while (R < L) { apply_i(L, ly, ry, neg), L = prev(L); }
  }

private:
  E get_i(int i, XY y) {
    E val = G::unit();
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    vc<int> Y_sub = {it, it + n};
    while (j < n) { val = G::op(val, dat[LID + j]), j = nxt(j); }
    return val;
  }

  void apply_i(int i, XY ly, XY ry, E val) {
    E neg = G::inverse(val);
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it - 1;
    int R = lower_bound(it, it + n, ry) - it - 1;
    while (L < R) { dat[LID + R] = G::op(val, dat[LID + R]), R = prev(R); }
    while (R < L) { dat[LID + L] = G::op(neg, dat[LID + L]), L = prev(L); }
  }
};
