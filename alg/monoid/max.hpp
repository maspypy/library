// require: all values x satisfy x >= -infty<E>
template <typename E>
struct Monoid_Max {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }
  static constexpr X id() { return -infty<E>; }
  static constexpr bool commute = true;
};
