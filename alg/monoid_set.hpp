template <typename E, E none_val>
struct Monoid_Set {
  using value_type = E;
  using X = value_type;
  static X op(X x, X y) { return (y == none_val ? x : y); }
  static constexpr X unit() { return none_val; }
  static constexpr bool commute = false;
};