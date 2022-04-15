template <typename T, T INF>
struct Monoid_Min_Idx {
  using value_type = pair<T, ll>;
  using X = value_type;
  static X op(X x, X y) { return min(x, y); }
  static constexpr X unit() { return {INF, -1}; }
  static constexpr bool commute = true;
};
