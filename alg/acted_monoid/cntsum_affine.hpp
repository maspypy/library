#include "alg/monoid/add_pair.hpp"
#include "alg/monoid/affine.hpp"

template <typename E>
struct ActedMonoid_CntSum_Affine {
  using Monoid_X = Monoid_Add_Pair<E>;
  using Monoid_A = Monoid_Affine<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.fi * a.se + x.se * a.fi};
  }
};
