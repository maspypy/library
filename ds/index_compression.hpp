template <typename T>
struct Index_Compression_DISTINCT_SMALL {
  int mi, ma;
  vc<T> dat;
  vc<T> build(vc<int> X) {
    mi = 0, ma = -1;
    if (!X.empty()) mi = MIN(X), ma = MAX(X);
    dat.assign(ma - mi + 2, 0);
    for (auto& x : X) dat[x - mi + 1]++;
    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
    for (auto& x : X) {
      x = dat[x - mi]++;
    }
    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];
    dat[0] = 0;
    return X;
  }
  int size() const { return len(dat); }
  int val_to_idx(T x) const { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }
  int idx_to_val(int i) const { return dat[i]; }
};

template <typename T>
struct Index_Compression_SAME_SMALL {
  int mi, ma;
  vc<T> dat;
  vc<T> build(vc<T> X) {
    mi = 0, ma = -1;
    if (!X.empty()) mi = MIN(X), ma = MAX(X);
    dat.assign(ma - mi + 2, 0);
    for (auto& x : X) dat[x - mi + 1] = 1;
    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
    for (auto& x : X) {
      x = dat[x - mi];
    }
    return X;
  }
  int size() const { return len(dat); }
  int val_to_idx(T x) const { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }
  int idx_to_val(int i) const { return dat[i]; }
};

template <typename T>
struct Index_Compression_SAME_LARGE {
  vc<T> dat;
  vc<int> build(const vc<T>& X) {
    dat.reserve(len(X));
    vc<pair<T, int>> tmp(len(X));
    FOR(i, len(X)) tmp[i] = {X[i], i};
    sort(all(tmp));
    vc<int> ANS(len(X));
    for (auto [x, j] : tmp) {
      if (dat.empty() || dat.back() != x) dat.eb(x);
      ANS[j] = len(dat) - 1;
    }
    return ANS;
  }
  int size() const { return len(dat); }
  int val_to_idx(T x) const { return LB(dat, x); }
  int idx_to_val(int i) const { return dat[i]; }
};

template <typename T>
struct Index_Compression_DISTINCT_LARGE {
  vc<T> dat;
  vc<int> build(vc<T> X) {
    dat.reserve(len(X));
    vc<pair<T, int>> tmp(len(X));
    FOR(i, len(X)) tmp[i] = {X[i], i};
    sort(all(tmp));
    vc<int> ANS(len(X));
    for (auto [x, j] : tmp) {
      dat.eb(x);
      ANS[j] = len(dat) - 1;
    }
    return ANS;
  }
  int size() const { return len(dat); }
  int val_to_idx(T x) const { return LB(dat, x); }
  int idx_to_val(int i) const { return dat[i]; }
};

template <typename T, bool SMALL>
using Index_Compression_DISTINCT =
    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,
                              Index_Compression_DISTINCT_LARGE<T>>::type;
template <typename T, bool SMALL>
using Index_Compression_SAME =
    typename std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,
                              Index_Compression_SAME_LARGE<T>>::type;

// SAME: [2,3,2] -> [0,1,0]
// DISTINCT: [2,2,3] -> [0,2,1]
// build で列を圧縮してくれる. そのあと
// (x): lower_bound(X,x) をかえす
template <typename T, bool SAME, bool SMALL>
using Index_Compression =
    typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,
                              Index_Compression_DISTINCT<T, SMALL>>::type;
