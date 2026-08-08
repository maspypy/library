#include "other/bit.hpp"
#include "linalg/xor/transpose.hpp"

/*
使い分け方針
Vector_Space: 線形空間そのものを管理
Basis: 元の基底による線形結合表示も管理
normalize=true : 簡約階段形を維持
normalize=false: 階段形（三角化）のみ維持。少し高速
*/
template <typename UINT, int MAX_DIM>
struct Vector_Space {
  static_assert(is_same_v<UINT, u32> || is_same_v<UINT, u64> ||
                is_same_v<UINT, u128>);
  int dim;
  array<UINT, MAX_DIM> dat;
  bool norm;

  Vector_Space() : dim(0), dat{}, norm(1) {}

  vc<UINT> to_vec() {
    vc<UINT> ANS;
    FOR_R(i, MAX_DIM) if (dat[i]) ANS.eb(dat[i]);
    return ANS;
  }

  int size() { return dim; }
  UINT add_element(UINT v, bool keep_normalized = false) {
    FOR_R(i, MAX_DIM) { chmin(v, v ^ dat[i]); }
    if (v == 0) return 0;
    int k = topbit(v);
    if (keep_normalized) {
      assert(norm);
      FOR(i, k + 1, MAX_DIM) chmin(dat[i], dat[i] ^ v);
    } else {
      norm = false;
    }
    dat[k] = v;
    ++dim;
    return v;
  }
  void normalize() {
    if (norm) return;
    norm = true;
    FOR(i, MAX_DIM) {
      if (dat[i] == 0) continue;
      FOR(j, i + 1, MAX_DIM) chmin(dat[j], dat[j] ^ dat[i]);
    }
  }

  bool contain(UINT v) {
    FOR_R(i, MAX_DIM) chmin(v, v ^ dat[i]);
    return v == 0;
  }

  UINT lower_bound(UINT x) {
    normalize();
    int d = dim;
    UINT ans = 0, now = 0;
    FOR_R(i, MAX_DIM) {
      if (dat[i] == 0) continue;
      --d;
      if ((now ^ dat[i]) < x) {
        ans += UINT(1) << d;
        now ^= dat[i];
      }
    }
    if (now < x) ans += 1;
    return ans;
  }

  UINT kth(UINT k) {
    if (dim < numeric_limits<UINT>::digits) {
      assert(k < (UINT(1) << dim));
    }
    normalize();
    int d = 0;
    UINT ans = 0;
    FOR(i, MAX_DIM) {
      if (dat[i] == 0) continue;
      if (k >> d & 1) ans ^= dat[i];
      ++d;
    }
    return ans;
  }

  UINT get_max(UINT xor_val = 0) {
    normalize();
    UINT res = xor_val;
    for (auto&& x : dat) chmax(res, res ^ x);
    return res;
  }

  UINT get_min(UINT xor_val = 0) {
    normalize();
    UINT res = xor_val;
    for (auto&& x : dat) chmin(res, res ^ x);
    return res;
  }

  static Vector_Space merge(Vector_Space x, Vector_Space y,
                            bool keep_normalized = false) {
    if (len(x) < len(y)) swap(x, y);
    for (auto v : y.dat) {
      x.add_element(v, keep_normalized);
    }
    return x;
  }

  static Vector_Space intersection(Vector_Space& x, Vector_Space& y) {
    // とりあえず
    static_assert(is_same_v<UINT, u32>);
    Vector_Space<u64, MAX_DIM * 2> z;
    for (auto v : x.dat) {
      if (v) z.add_element(v | static_cast<u64>(v) << MAX_DIM);
    }
    for (auto v : y.dat) {
      if (v) z.add_element(static_cast<u64>(v) << MAX_DIM);
    }
    Vector_Space<UINT, MAX_DIM> ANS;
    for (auto& v : z.dat) {
      if (v <= u32(-1)) ANS.add_element(v);
    }
    return ANS;
  }

  static array<UINT, MAX_DIM> transpose(array<UINT, MAX_DIM> A) {
    constexpr int L = numeric_limits<UINT>::digits;
    array<UINT, L> B{};
    FOR(i, MAX_DIM) B[i] = A[i];
    int LOG = 0;
    while ((1 << LOG) < L) ++LOG;
    int width = 1 << LOG;
    UINT mask = -1;
    FOR(t, LOG) {
      width >>= 1;
      mask = mask ^ (mask >> width);
      FOR(i, 1 << t) {
        FOR(j, width) {
          UINT* x = &B[width * (2 * i + 0) + j];
          UINT* y = &B[width * (2 * i + 1) + j];
          *x = ((*y << width) & mask) ^ *x;
          *y = ((*x & mask) >> width) ^ *y;
          *x = ((*y << width) & mask) ^ *x;
        }
      }
    }
    FOR(i, MAX_DIM) A[i] = B[i];
    return A;
  }

  Vector_Space orthogonal_space(bool keep_normalize = false) {
    normalize();
    array<UINT, MAX_DIM> T = transpose(dat);
    Vector_Space ANS;
    FOR_R(j, MAX_DIM) {
      if (T[j] >> j & 1) continue;
      ANS.add_element((UINT(1) << j) | T[j], keep_normalize);
    }
    return ANS;
  }
};
