#include "alg/monoid/monoid_reverse.hpp"

template <typename ActedMonoid>
struct ActedMonoid_Reverse {
  using Monoid_X = Monoid_Reverse<typename ActedMonoid::Monoid_X>;
  using Monoid_A = typename ActedMonoid::Monoid_A;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) { return Lazy::act(x, a); }
};
