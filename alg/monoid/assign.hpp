// Source: https://github.com/maspypy/library/blob/main/alg/monoid/assign.hpp

template <typename X>
struct Monoid_Assign {
  static_assert(is_same_v<X, int> || is_same_v<X, ll>);
  static constexpr X none_val = numeric_limits<X>::max();
  using value_type = X;
  static X op(X x, X y) { return (y == none_val ? x : y); }
  static constexpr X id() { return none_val; }
  static constexpr bool commute = false;
};
