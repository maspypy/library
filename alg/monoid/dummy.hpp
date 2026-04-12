struct Monoid_Dummy {
  using value_type = char;
  static constexpr bool commute = true;
  static value_type op(value_type, value_type) { return 0; }
  static value_type unit() { return 0; }
};
