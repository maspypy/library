// template/monoid.hpp
struct Mono {
  using value_type = ;
  using X = value_type;
  static X op(X L, X R) { return {}; }
  static constexpr X id() { return; }
  static constexpr bool commute = ;
};
