
struct Monoid_XorBasis {
  using value_type = ARR;
  using VECT_SP = value_type;
  // 破壊的に変更する。
  static inline bool add_element(VECT_SP& x, u64 v) {
    for (auto&& e: x) {
      if (v == 0) break;
      if (e == 0) {
        e = v; // v を追加
        return true;
      }
      chmin(v, v ^ e);
    }
    return false;
  }

  static u64 get_max(const VECT_SP& V) {
    u64 res = 0;
    for (auto&& x: V) chmax(res, res ^ x);
    return res;
  }
  static constexpr VECT_SP unit() { return VECT_SP(); };
  static constexpr bool commute = true;
};