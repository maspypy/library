#pragma once

template <typename E>
struct Monoid_XorBasis {
  using value_type = vector<E>;
  using VECT_SP = value_type;
  // 破壊的に変更する
  static bool add_element(VECT_SP& x, E v) {
    for (auto&& e: x) {
      if (e == 0 || v == 0) break;
      chmin(v, v ^ e);
    }
    if (v) {
      x.eb(v);
      return true;
    }
    return false;
  }

  static VECT_SP op(const VECT_SP x, const VECT_SP y) {
    for (auto v: y) { add_element(x, v); }
    return x;
  }

  static bool isin(E v, const VECT_SP& V) {
    for (auto&& w: V) { chmin(v, v ^ w); }
    return v == 0;
  }

  static E get_max(const VECT_SP& V, E xor_val = 0) {
    E res = xor_val;
    for (auto&& x: V) chmax(res, res ^ x);
    return res;
  }

  static E get_min(const VECT_SP& V, E xor_val = 0) {
    E res = xor_val;
    for (auto&& x: V) chmin(res, res ^ x);
    return res;
  }
  static constexpr VECT_SP unit() { return VECT_SP{}; };
  static constexpr bool commute = true;
};
