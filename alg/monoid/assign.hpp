template <typename X, X none_val>
struct Monoid_Assign {
  using value_type = X;
  static X op(X x, X y) { return (y == none_val ? x : y); }
  static constexpr X unit() { return none_val; }
  static constexpr bool commute = false;
};
