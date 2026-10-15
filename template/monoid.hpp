// Source: https://github.com/maspypy/library/blob/main/template/monoid.hpp
// template/monoid.hpp
struct Mono {
  using value_type = ;
  using X = value_type;
  static X op(const X& L, const X& R) { return {}; }
  static constexpr X id() { return; }
  static constexpr bool commute = ;
};
