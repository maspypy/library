template <class Monoid>
struct DefaultUnitProd {
  using X = typename Monoid::value_type;
  static constexpr bool unit_only = true;
  X operator()(long long, long long) const { return Monoid::unit(); }
};
