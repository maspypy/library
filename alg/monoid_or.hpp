template <typename E>
struct Monoid_Or {
  using value_type = E;
  using X = value_type;
  static X op(X x, X y) { return x | y; }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};
