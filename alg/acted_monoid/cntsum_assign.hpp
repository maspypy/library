#include "alg/monoid/add_pair.hpp"
#include "alg/monoid/assign.hpp"

template <typename E, E none_val>
struct ActedMonoid_CntSum_Assign {
  using X_structure = Monoid_Add_Pair<E>;
  using A_structure = Monoid_Set<E, none_val>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (a == A_structure::unit()) return x;
    return {x.fi, x.fi * a};
  }
};
