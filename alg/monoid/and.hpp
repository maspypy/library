template <typename E>
struct Monoid_And {
  using value_type = E;
  using X = value_type;
  static X op(X x, X y) { return x & y; }
  static constexpr X unit() { return numeric_limits<E>::max(); }
  static constexpr bool commute = true;
};
