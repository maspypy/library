template <typename E>
struct Monoid_XorBasis {
  using value_type = vector<E>;
  using X = value_type;

  // 破壊的に変更する
  static bool add_element(X& x, E v) {
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

  static X op(const X& x, const X& y) {
    X z = x;
    for (auto v: y) { add_element(z, v); }
    return z;
  }

  static bool isin(E v, const X& x){
    for(auto&& w : x){
      chmin(v, v ^ w);
    }
    return v == 0;
  }

  // x ^ v の最大値
  static E get_max(const X& x) {
    INT res = 0;
    for (auto&& a: x) chmax(res, res ^ a);
    return res;
  }
  static constexpr X unit() { return X{}; };
  static constexpr bool commute = true;
};
