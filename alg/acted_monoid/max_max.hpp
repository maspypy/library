#include "alg/monoid/max.hpp"

template <typename E>
struct ActedMonoid_Max_Max {
  using Monoid_X = Monoid_Max<E>;
  using Monoid_A = Monoid_Max<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) { return max(x, a); }
};
