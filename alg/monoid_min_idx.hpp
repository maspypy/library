template <typename T, bool tie_is_left = true>
struct Monoid_Min_Idx {
  using value_type = pair<T, ll>;
  using X = value_type;
  static X op(X x, X y) {
    if (x.fi < y.fi) return x;
    if (x.fi > y.fi) return y;
    return (tie_is_left ? x : y);
  }
  static constexpr X unit() { return {numeric_limits<T>::max(), -1}; }
  static constexpr bool commute = true;
};
