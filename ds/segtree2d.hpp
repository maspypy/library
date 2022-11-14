template <typename Monoid, typename XY, bool SMALL = false>
struct SegTree2D {
  using S = typename Monoid::value_type;
  int N;
  int full_N;
  vc<XY> keyX;
  int min_X;
  vc<int> indptr;
  vc<XY> keyY;
  vc<S> dat;

  inline int xtoi(XY x) {
    if (SMALL) return clamp<XY>(x - min_X, 0, N);
    return LB(keyX, x);
  }

  SegTree2D(vc<XY>& X, vc<XY>& Y, vc<S> wt = vc<S>()) {
    if (len(wt) == 0) wt = vc<S>(len(X), Monoid::unit());
    assert(Monoid::commute); // 可換モノイドのみ
    assert(len(X) == len(Y) && len(X) == len(wt));

    if (!SMALL) {
      keyX = X;
      UNIQUE(keyX);
      N = len(keyX);
    } else {
      min_X = (len(X) == 0 ? 0 : MIN(X));
      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;
      keyX.resize(N);
      FOR(i, N) keyX[i] = min_X + i;
    }

    vc<vc<XY>> keyY_raw(N + N);
    vc<vc<S>> dat_raw(N + N);

    auto I = argsort(Y);
    for (auto&& i: I) {
      int ix = xtoi(X[i]), y = Y[i];
      ix += N;
      while (ix) {
        auto& KY = keyY_raw[ix];
        if (len(KY) == 0 || KY.back() < y) {
          KY.eb(y);
          dat_raw[ix].eb(wt[i]);
        } else {
          dat_raw[ix].back() = Monoid::op(dat_raw[ix].back(), wt[i]);
        }
        ix >>= 1;
      }
    }

    indptr.assign(N + N + 1, 0);
    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);
    int full_N = indptr.back();
    keyY.resize(full_N);
    dat.assign(2 * full_N, Monoid::unit());
    FOR(i, N + N) {
      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];
      FOR(j, n) {
        keyY[indptr[i] + j] = keyY_raw[i][j];
        dat[off + n + j] = dat_raw[i][j];
      }
      FOR3_R(j, 1, n)
      dat[off + j] = Monoid::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);
    }
  }

  void multiply_i(int i, XY y, S val) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    assert(keyY[LID + j] == y);
    int off = 2 * LID;
    j += n;

    while (j) {
      dat[off + j] = Monoid::op(dat[off + j], val);
      j >>= 1;
    }
  }

  void multiply(XY x, XY y, S val) {
    int i = xtoi(x);
    assert(keyX[i] == x);
    i += N;
    while (i) {
      multiply_i(i, y, val);
      i >>= 1;
    }
  }

  S prod_i(int i, XY ly, XY ry) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it;
    int R = lower_bound(it, it + n, ry) - it;
    int off = 2 * LID;
    L += n;
    R += n;
    S val = Monoid::unit();
    while (L < R) {
      if (L & 1) val = Monoid::op(val, dat[off + (L++)]);
      if (R & 1) val = Monoid::op(dat[off + (--R)], val);
      L >>= 1;
      R >>= 1;
    }
    return val;
  }

  S prod(XY lx, XY rx, XY ly, XY ry) {
    int L = xtoi(lx);
    int R = xtoi(rx);
    L += N;
    R += N;
    S val = Monoid::unit();
    while (L < R) {
      if (L & 1) val = Monoid::op(val, prod_i(L++, ly, ry));
      if (R & 1) val = Monoid::op(prod_i(--R, ly, ry), val);
      L >>= 1;
      R >>= 1;
    }
    return val;
  }

  void debug() {
    print("keyX", keyX);
    print("indptr", indptr);
    print("keyY", keyY);
    print("dat", dat);
  }
};