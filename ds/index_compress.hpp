template <typename T>
struct To_Unique_Index_SMALL {
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
struct To_Unique_Index_LARGE {
  vc<T> dat;
  vc<int> build(vc<T> X) {
    vc<int> I = argsort(X);
    dat = rearrange(X, I);
    sort(all(dat));
    vc<int> res(len(X));
    FOR(i, len(X)) res[I[i]] = i;
    return res;
  }
  int operator()(T x) { return LB(dat, x); }
};

// まず X の各要素を [0,n) にうつす, 単射にする
// [2,2,3] -> [0,1,2]
// (x): lower_bound(X,x) をかえす
template <typename T, bool SMALL>
using To_Unique_Index =
    typename std::conditional<SMALL, To_Unique_Index_SMALL<T>,
                              To_Unique_Index_LARGE<T>>::type;
