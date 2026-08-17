// template/actedmonoid.hpp
struct ActedMonoid {
  using Monoid_X = ;
  using Monoid_A = ;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static X act(const X &x, const A &a, const ll &size) { return; }
};