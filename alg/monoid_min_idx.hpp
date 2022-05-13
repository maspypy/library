template <typename T>
struct Monoid_Min_Idx {
  using value_type = pair<T, ll>;
  using X = value_type;
  static X op(X x, X y) { return min(x, y); }
  static constexpr X unit() { return {numeric_limits<T>::max(), -1}; }
  static constexpr bool commute = true;
};
