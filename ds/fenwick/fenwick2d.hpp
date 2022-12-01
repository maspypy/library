#include "alg/monoid/add.hpp"
template <typename AbelGroup, typename XY, bool SMALL_X = false>
struct Fenwick2D {
  using E = typename AbelGroup::value_type;
  int N;
  vc<XY> keyX;
  XY min_X;
  vc<int> indptr;
  vc<XY> keyY;
  vc<E> dat;

  Fenwick2D(vc<XY>& X, vc<XY>& Y, vc<E>& wt) { build(X, Y, wt); }

  Fenwick2D(vc<XY>& X, vc<XY>& Y) {
    vc<E> wt(len(X), AbelGroup::unit());
    build(X, Y, wt);
  }

  void reset_value() { fill(all(dat), AbelGroup::unit()); }

  inline int xtoi(XY x) {
    return (SMALL_X ? clamp<int>(x - min_X, 0, N) : LB(keyX, x));
  }

  inline int nxt(int i) {
    i += 1;
    return i + (i & -i) - 1;
  }

  inline int prev(int i) {
    i += 1;
    return i - (i & -i) - 1;
  }

  void build(vc<XY>& X, vc<XY>& Y, vc<E>& wt) {
    if (!SMALL_X) {
      keyX = X;
      UNIQUE(keyX);
      N = len(keyX);
    } else {
      min_X = (len(X) == 0 ? 0 : MIN(X));
      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;
      keyX.resize(N);
      FOR(i, N) keyX[i] = min_X + i;
    }

    vvc<XY> keyY_raw(N);
    vc<vc<E>> dat_raw(N);

    auto I = argsort(Y);
    for (auto&& i: I) {
      int ix = xtoi(X[i]);
      ll y = Y[i];
      while (ix < N) {
        auto& KY = keyY_raw[ix];
        if (len(KY) == 0 || KY.back() < y) {
          KY.eb(y);
          dat_raw[ix].eb(wt[i]);
        } else {
          dat_raw[ix].back() = AbelGroup::op(dat_raw[ix].back(), wt[i]);
        }
        ix = nxt(ix);
      }
    }

    indptr.assign(N + 1, 0);
    FOR(i, N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);
    keyY.resize(indptr.back());
    dat.resize(indptr.back());
    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i]) {
      keyY[indptr[i] + j] = keyY_raw[i][j];
      dat[indptr[i] + j] = dat_raw[i][j];
    }
    FOR(i, N) {
      int n = indptr[i + 1] - indptr[i];
      FOR(j, n - 1) {
        int k = nxt(j);
        if (k < n)
          dat[indptr[i] + k]
              = AbelGroup::op(dat[indptr[i] + k], dat[indptr[i] + j]);
      }
    }
  }

  void multiply(XY x, XY y, E val) {
    int i = xtoi(x);
    assert(keyX[i] == x);
    while (i < N) {
      multiply_i(i, y, val);
      i = nxt(i);
    }
  }

  void add(XY x, XY y, E val) { multiply(x, y, val); }

  E prod(XY lx, XY rx, XY ly, XY ry) {
    E pos = AbelGroup::unit();
    E neg = AbelGroup::unit();
    int L = xtoi(lx) - 1;
    int R = xtoi(rx) - 1;
    while (L < R) {
      pos = AbelGroup::op(pos, prod_i(R, ly, ry));
      R = prev(R);
    }
    while (R < L) {
      neg = AbelGroup::op(neg, prod_i(L, ly, ry));
      L = prev(L);
    }
    E ret = AbelGroup::op(pos, AbelGroup::inverse(neg));
    return ret;
  }

  E prefix_prod(XY rx, XY ry) {
    E pos = AbelGroup::unit();
    int R = xtoi(rx) - 1;
    while (R >= 0) {
      pos = AbelGroup::op(pos, prefix_prod_i(R, ry));
      R = prev(R);
    }
    return pos;
  }

  E sum(XY lx, XY rx, XY ly, XY ry) { return prod(lx, rx, ly, ry); }

  E prefix_sum(XY rx, XY ry) { return prefix_prod(rx, ry); }

  void debug() {
    print("keyX", keyX);
    print("indptr", indptr);
    print("keyY", keyY);
    print("dat", dat);
  }

private:
  void multiply_i(int i, XY y, E val) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    assert(keyY[LID + j] == y);
    while (j < n) {
      dat[LID + j] = AbelGroup::op(dat[LID + j], val);
      j = nxt(j);
    }
  }

  E prod_i(int i, XY ly, XY ry) {
    E pos = AbelGroup::unit();
    E neg = AbelGroup::unit();
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it - 1;
    int R = lower_bound(it, it + n, ry) - it - 1;
    while (L < R) {
      pos = AbelGroup::op(pos, dat[LID + R]);
      R = prev(R);
    }
    while (R < L) {
      neg = AbelGroup::op(neg, dat[LID + L]);
      L = prev(L);
    }
    return AbelGroup::op(pos, AbelGroup::inverse(neg));
  }

  E prefix_prod_i(int i, XY ry) {
    E pos = AbelGroup::unit();
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int R = lower_bound(it, it + n, ry) - it - 1;
    while (R >= 0) {
      pos = AbelGroup::op(pos, dat[LID + R]);
      R = prev(R);
    }
    return pos;
  }
};
