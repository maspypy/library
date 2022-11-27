#include "alg/monoid/cntsum.hpp"
#include "alg/monoid/set.hpp"

template <typename E, E none_val>
struct Lazy_CntSum_Set {
  using X_structure = Group_CntSum<E>;
  using A_structure = Monoid_Set<E, none_val>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (a == A_structure::unit()) return x;
    return {x.fi, x.fi * a};
  }
};
