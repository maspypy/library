#include "alg/monoid/add.hpp"
#include "alg/monoid/mul.hpp"

template <typename E>
struct ActedMonoid_Add_Mul {
  using Monoid_X = Monoid_Add<E>;
  using Monoid_A = Monoid_Mul<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) { return x * a; }
};
