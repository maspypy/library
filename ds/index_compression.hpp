template <typename T>
struct Index_Compression_DISTINCT_SMALL {
  static_assert(is_same_v<T, int>);
  int mi, ma;
  vc<int> dat;
  vc<int> build(vc<int> X) {
    mi = 0, ma = -1;
    if (!X.empty()) mi = MIN(X), ma = MAX(X);
    dat.assign(ma - mi + 2, 0);
    for (auto& x: X) dat[x - mi + 1]++;
    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
    for (auto& x: X) { x = dat[x - mi]++; }
    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];
    dat[0] = 0;
    return X;
  }
  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }
};

template <typename T>
struct Index_Compression_SAME_SMALL {
  static_assert(is_same_v<T, int>);
  int mi, ma;
  vc<int> dat;
  vc<int> build(vc<int> X) {
    mi = 0, ma = -1;
    if (!X.empty()) mi = MIN(X), ma = MAX(X);
    dat.assign(ma - mi + 2, 0);
    for (auto& x: X) dat[x - mi + 1] = 1;
    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
    for (auto& x: X) { x = dat[x - mi]; }
    return X;
  }
  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }
};

template <typename T>
struct Index_Compression_SAME_LARGE {
  vc<T> dat;
  vc<int> build(vc<T> X) {
    vc<int> I = argsort(X);
    vc<int> res(len(X));
    for (auto& i: I) {
      if (!dat.empty() && dat.back() == X[i]) {
        res[i] = len(dat) - 1;
      } else {
        res[i] = len(dat);
        dat.eb(X[i]);
      }
    }
    dat.shrink_to_fit();
    return res;
  }
  int operator()(T x) { return LB(dat, x); }
};

template <typename T>
struct Index_Compression_DISTINCT_LARGE {
  vc<T> dat;
  vc<int> build(vc<T> X) {
    vc<int> I = argsort(X);
    vc<int> res(len(X));
    for (auto& i: I) { res[i] = len(dat), dat.eb(X[i]); }
    dat.shrink_to_fit();
    return res;
  }
  int operator()(T x) { return LB(dat, x); }
};

template <typename T, bool SMALL>
using Index_Compression_DISTINCT = typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>, Index_Compression_DISTINCT_LARGE<T>>::type;
template <typename T, bool SMALL>
using Index_Compression_SAME = typename std::conditional<SMALL, Index_Compression_SAME_SMALL<T>, Index_Compression_SAME_LARGE<T>>::type;

// SAME: [2,3,2] -> [0,1,0]
// DISTINCT: [2,2,3] -> [0,2,1]
// build で列を圧縮してくれる. そのあと
// (x): lower_bound(X,x) をかえす
template <typename T, bool SAME, bool SMALL>
using Index_Compression = typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>, Index_Compression_DISTINCT<T, SMALL>>::type;
