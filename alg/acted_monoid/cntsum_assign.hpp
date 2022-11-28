#include "alg/monoid/add_pair.hpp"
#include "alg/monoid/assign.hpp"

template <typename E, E none_val>
struct ActedMonoid_CntSum_Assign {
  using Monoid_X = Monoid_Add_Pair<E>;
  using Monoid_A = Monoid_Assign<E, none_val>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (a == Monoid_A::unit()) return x;
    return {x.fi, x.fi * a};
  }
};
