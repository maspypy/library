template <typename E1, typename E2, typename E3>
struct Monoid_Add_Tuple_3 {
  using value_type = tuple<E1, E2, E3>;
  using X = value_type;
  static X op(X x, X y) {
    auto [x0, x1, x2] = x;
    auto [y0, y1, y2] = y;
    return {x0 + y0, x1 + y1, x2 + y2};
  }
  static X inverse(X x) {
    auto [x0, x1, x2] = x;
    return {-x0, -x1, -x2};
  }
  static constexpr X unit() { return {E1(0), E2(0), E3(0)}; }
  static constexpr bool commute = 1;
};