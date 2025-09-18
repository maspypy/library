#include "linalg/xor/transpose.hpp"

template <typename UINT, int MAX_DIM>
struct Vector_Space {
  static_assert(is_same_v<UINT, u32> || is_same_v<UINT, u64> ||
                is_same_v<UINT, u128>);
  int dim;
  array<UINT, MAX_DIM> dat;

  Vector_Space() : dim(0), dat{} {}

  bool add_element(UINT v) {
    FOR_R(i, MAX_DIM) { chmin(v, v ^ dat[i]); }
    if (v == 0) return 0;
    FOR(i, MAX_DIM) {
      if (dat[i] != 0) chmin(dat[i], dat[i] ^ v);
    }
    dat[topbit(v)] = v;
    ++dim;
    return true;
  }

  bool contain(UINT v) {
    for (UINT w : dat) {
      chmin(v, v ^ w);
    }
    return v == 0;
  }

  UINT lower_bound(UINT x) {
    int d = dim;
    u32 ans = 0, now = 0;
    FOR_R(i, MAX_DIM) {
      if (dat[i] == 0) continue;
      --d;
      SHOW(now, ans, dat[i], x);
      if ((now ^ dat[i]) < x) {
        ans += UINT(1) << d;
        now ^= dat[i];
      }
    }
    if (now < x) ans += 1;
    return ans;
  }

  UINT kth(UINT k) {
    assert(k < (UINT(1) << dim));
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
    UINT res = xor_val;
    for (auto&& x : dat) chmax(res, res ^ x);
    return res;
  }

  UINT get_min(UINT xor_val = 0) {
    UINT res = xor_val;
    for (auto&& x : dat) chmin(res, res ^ x);
    return res;
  }

  static Vector_Space merge(Vector_Space x, Vector_Space y) {
    if (len(x) < len(y)) swap(x, y);
    for (auto v : y.dat) {
      x.add_element(v);
    }
    return x;
  }

  static Vector_Space intersection(Vector_Space& x, Vector_Space& y) {
    // とりあえず
    static_assert(is_same_v<UINT, u32>);
    vc<u64> xx;
    for (auto& v : x.dat) xx.eb(v | static_cast<u64>(v) << 32);
    Vector_Space<u64, MAX_DIM * 2> z(xx, true);
    for (auto& v : y.dat) z.add_element(static_cast<u64>(v) << 32);
    Vector_Space<UINT, MAX_DIM> ANS;
    for (auto& v : z.dat) {
      if (v <= u32(-1)) ANS.add_element(v);
    }
    return ANS;
  }
};
