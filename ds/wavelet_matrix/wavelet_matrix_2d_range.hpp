#include "ds/wavelet_matrix/wavelet_matrix.hpp"

template <typename XY, bool SMALL_X, bool SMALL_Y, typename SEGTREE = Dummy_Data_Structure>
struct Wavelet_Matrix_2D_Range {
  // 点群を X 昇順に並べる.
  Wavelet_Matrix<XY, SMALL_Y, SEGTREE> WM;
  using Mono = typename SEGTREE::MX;
  using T = typename Mono::value_type;
  static_assert(Mono::commute);

  Index_Compression<XY, false, SMALL_X> IDX_X;

  int n;
  vc<int> new_idx;

  template <typename F>
  Wavelet_Matrix_2D_Range(int n, F f) {
    build(n, f);
  }

  template <typename F>
  void build(int m, F f) {
    n = m;
    vc<XY> X(n), Y(n);
    vc<T> S(n);
    FOR(i, n) {
      auto tmp = f(i);
      X[i] = get<0>(tmp), Y[i] = get<1>(tmp), S[i] = get<2>(tmp);
    }
    new_idx = IDX_X.build(X);
    vc<int> I(n);
    FOR(i, n) I[new_idx[i]] = i;
    Y = rearrange(Y, I);
    S = rearrange(S, I);
    WM.build(Y, S);
  }

  int count(XY x1, XY x2, XY y1, XY y2) { return WM.count(IDX_X(x1), IDX_X(x2), y1, y2); }

  // [L,R) x [-inf,y)
  pair<int, T> prefix_count_and_prod(XY x1, XY x2, XY y) { return WM.prefix_count_and_prod(IDX_X(x1), IDX_X(x2), y); }

  // [L,R) x [y1,y2)
  pair<int, T> count_and_prod(XY x1, XY x2, XY y1, XY y2) { return WM.count_and_prod(IDX_X(x1), IDX_X(x2), y1, y2); }

  // [L,R) x [-inf,inf)
  T prod_all(XY x1, XY x2) { return WM.prod_all(IDX_X(x1), IDX_X(x2)); }
  // [L,R) x [-inf,y)
  T prefix_prod(XY x1, XY x2, XY y) { return WM.prefix_prod(IDX_X(x1), IDX_X(x2), y); }
  // [L,R) x [y1,y2)
  T prod(XY x1, XY x2, XY y1, XY y2) { return WM.prod(IDX_X(x1), IDX_X(x2), y1, y2); }

  // [L,R) x [-inf,y) での check(cnt, prod) が true となる最大の (cnt,prod)
  template <typename F>
  pair<int, T> max_right(F check, XY x1, XY x2) {
    return WM.max_right(check, IDX_X(x1), IDX_X(x2));
  }

  // i は最初に渡したインデックス
  void set(int i, T t) { WM.set(new_idx[i], t); }
  // i は最初に渡したインデックス
  void multiply(int i, T t) { WM.multiply(new_idx[i], t); }
  void add(int i, T t) { WM.multiply(new_idx[i], t); }
};