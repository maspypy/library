template <typename INT>
struct Monoid_Gcd {
  using value_type = INT;
  using X = value_type;
  static X op(X x, X y) { return gcd(x, y); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute = true;
};
