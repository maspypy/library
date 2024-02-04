#include "ds/bit_vector.hpp"

template <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>
struct Wavelet_Matrix_2D_Range_Static_AbelGroup {
  // 点群を Y 昇順に並べる.
  // X を整数になおして binary trie みたいに振り分ける
  using MX = Monoid;
  using X = typename MX::value_type;
  static_assert(MX::commute);

  template <bool SMALL>
  struct TO_IDX {
    vc<XY> key;
    XY mi, ma;
    vc<int> dat;

    void build(vc<XY>& X) {
      if constexpr (SMALL) {
        mi = (X.empty() ? 0 : MIN(X));
        ma = (X.empty() ? 0 : MAX(X));
        dat.assign(ma - mi + 2, 0);
        for (auto& x: X) { dat[x - mi + 1]++; }
        FOR(i, len(dat) - 1) dat[i + 1] += dat[i];
      } else {
        key = X;
        sort(all(key));
      }
    }
    int operator()(XY x) {
      if constexpr (SMALL) {
        return dat[clamp<XY>(x - mi, 0, ma - mi + 1)];
      } else {
        return LB(key, x);
      }
    }
  };

  TO_IDX<SMALL_X> XtoI;
  TO_IDX<SMALL_Y> YtoI;

  int N, lg;
  vector<int> mid;
  vector<Bit_Vector> bv;
  vvc<X> dat;

  template <typename F>
  Wavelet_Matrix_2D_Range_Static_AbelGroup(int N, F f) {
    build(N, f);
  }

  template <typename F>
  void build(int N, F f) {
    if (N == 0) {
      lg = 0;
      return;
    }
    vc<XY> A(N), Y(N);
    vc<X> S(N);
    FOR(i, N) tie(A[i], Y[i], S[i]) = f(i);
    auto I = argsort(Y);
    A = rearrange(A, I), Y = rearrange(Y, I), S = rearrange(S, I);
    XtoI.build(A), YtoI.build(Y);

    // あとは普通に
    lg = __lg(XtoI(MAX(A) + 1)) + 1;
    mid.resize(lg), bv.assign(lg, Bit_Vector(N));
    dat.assign(1 + lg, vc<X>(N + 1, MX::unit()));
    FOR(i, N) A[i] = XtoI(A[i]);

    vc<int> A0(N), A1(N);
    vc<X> S0(N), S1(N);
    FOR_R(d, -1, lg) {
      int p0 = 0, p1 = 0;
      FOR(i, N) { dat[d + 1][i + 1] = MX::op(dat[d + 1][i], S[i]); }
      if (d == -1) break;
      FOR(i, N) {
        bool f = (A[i] >> d & 1);
        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }
        if (f) { S1[p1] = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }
      }
      mid[d] = p0;
      bv[d].build();
      swap(A, A0), swap(S, S0);
      FOR(i, p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
    }
  }

  int count(XY x1, XY x2, XY y1, XY y2) {
    x1 = XtoI(x1), x2 = XtoI(x2);
    y1 = YtoI(y1), y2 = YtoI(y2);
    return prefix_count(y1, y2, x2) - prefix_count(y1, y2, x1);
  }

  X prod(XY x1, XY x2, XY y1, XY y2) { return sum(x1, x2, y1, y2); }
  X sum(XY x1, XY x2, XY y1, XY y2) {
    assert(x1 <= x2 && y1 <= y2);
    x1 = XtoI(x1), x2 = XtoI(x2);
    y1 = YtoI(y1), y2 = YtoI(y2);
    X add = prefix_sum(y1, y2, x2);
    X sub = prefix_sum(y1, y2, x1);
    return MX::op(add, MX::inverse(sub));
  }

private:
  int prefix_count(int L, int R, int x) {
    int cnt = 0;
    FOR_R(d, lg) {
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      if (x >> d & 1) {
        cnt += r0 - l0, L += mid[d] - l0, R += mid[d] - r0;
      } else {
        L = l0, R = r0;
      }
    }
    return cnt;
  }

  X prefix_sum(int L, int R, int x) {
    X add = MX::unit(), sub = MX::unit();
    FOR_R(d, lg) {
      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
      if (x >> d & 1) {
        add = MX::op(add, dat[d][r0]);
        sub = MX::op(sub, dat[d][l0]);
        L += mid[d] - l0, R += mid[d] - r0;
      } else {
        L = l0, R = r0;
      }
    }
    return MX::op(add, MX::inverse(sub));
  }
};