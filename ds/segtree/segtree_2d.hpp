template <typename Monoid, typename XY, bool SMALL = false>
struct SegTree_2D {
  using MX = Monoid;
  using S = typename MX::value_type;
  static_assert(MX::commute);
  int N, min_X;
  vc<XY> keyX, keyY;
  vc<int> indptr;
  vc<S> dat;

  SegTree_2D(vc<XY>& X, vc<XY>& Y, vc<S> wt = vc<S>()) {
    if (len(wt) == 0) wt = vc<S>(len(X), MX::unit());
    assert(len(X) == len(Y) && len(X) == len(wt));
    if (!SMALL) {
      keyX = X;
      UNIQUE(keyX);
      N = len(keyX);
      keyX.shrink_to_fit();
    } else {
      min_X = (len(X) == 0 ? 0 : MIN(X));
      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;
      keyX.resize(N);
      FOR(i, N) keyX[i] = min_X + i;
    }

    vvc<XY> keyY_raw(N + N);
    vvc<S> dat_raw(N + N);
    for (auto&& i: argsort(Y)) {
      int ix = xtoi(X[i]), y = Y[i];
      ix += N;
      while (ix) {
        auto& KY = keyY_raw[ix];
        if (len(KY) == 0 || KY.back() < y) {
          KY.eb(y);
          dat_raw[ix].eb(wt[i]);
        } else {
          dat_raw[ix].back() = MX::op(dat_raw[ix].back(), wt[i]);
        }
        ix >>= 1;
      }
    }

    indptr.assign(N + N + 1, 0);
    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);
    int full_N = indptr.back();
    keyY.resize(full_N), dat.assign(2 * full_N, MX::unit());
    FOR(i, N + N) {
      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];
      FOR(j, n) {
        keyY[indptr[i] + j] = keyY_raw[i][j];
        dat[off + n + j] = dat_raw[i][j];
      }
      FOR_R(j, 1, n) {
        dat[off + j] = MX::op(dat[off + 2 * j], dat[off + 2 * j + 1]);
      }
    }
  }

  void multiply(XY x, XY y, S val) {
    int i = xtoi(x);
    assert(keyX[i] == x);
    i += N;
    while (i) { multiply_i(i, y, val), i >>= 1; }
  }

  S prod(XY lx, XY rx, XY ly, XY ry) {
    int L = xtoi(lx) + N, R = xtoi(rx) + N;
    S val = MX::unit();
    while (L < R) {
      if (L & 1) val = MX::op(val, prod_i(L++, ly, ry));
      if (R & 1) val = MX::op(prod_i(--R, ly, ry), val);
      L >>= 1, R >>= 1;
    }
    return val;
  }

private:
  inline int xtoi(XY x) {
    return (SMALL ? clamp<XY>(x - min_X, 0, N) : LB(keyX, x));
  }
  S prod_i(int i, XY ly, XY ry) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it + n;
    int R = lower_bound(it, it + n, ry) - it + n;
    int off = 2 * LID;
    S val = MX::unit();
    while (L < R) {
      if (L & 1) val = MX::op(val, dat[off + (L++)]);
      if (R & 1) val = MX::op(dat[off + (--R)], val);
      L >>= 1, R >>= 1;
    }
    return val;
  }
  void multiply_i(int i, XY y, S val) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    assert(keyY[LID + j] == y);
    int off = 2 * LID;
    j += n;
    while (j) {
      dat[off + j] = MX::op(dat[off + j], val);
      j >>= 1;
    }
  }
};