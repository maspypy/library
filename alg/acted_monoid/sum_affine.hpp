#include "alg/monoid/add.hpp"
#include "alg/monoid/affine.hpp"

template <typename E>
struct ActedMonoid_Sum_Affine {
  using Monoid_X = Monoid_Add<E>;
  using Monoid_A = Monoid_Affine<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    return x * a.fi + E(size) * a.se;
  }
};
