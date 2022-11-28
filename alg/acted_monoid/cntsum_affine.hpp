#include "alg/monoid/add_pair.hpp"
#include "alg/monoid/affine.hpp"

template <typename E>
struct Lazy_CntSum_Affine {
  using X_structure = Monoid_Add_Pair<E>;
  using A_structure = Monoid_Affine<E>;
  using X = typename X_structure::value_type;
  using A = typename A_structure::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.fi * a.se + x.se * a.fi};
  }
};
