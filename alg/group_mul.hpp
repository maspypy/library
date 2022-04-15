template <class X>
struct Group_Mul {
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x * y; }
  static constexpr X inverse(const X &x) noexcept { return X(1) / x; }
  static constexpr X unit() { return X(1); }
  static constexpr bool commute = true;
};
