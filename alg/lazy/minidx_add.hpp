#include "alg/monoid/add.hpp"
#include "alg/monoid/min_idx.hpp"

template <typename E, bool tie_is_left = true>
struct Lazy_MinIdx_Add {
  using MX = Monoid_Min_Idx<E, tie_is_left>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (x.fi == numeric_limits<E>::max()) return x;
    return {x.fi + a, x.se};
  }
};
