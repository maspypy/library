#include "alg/monoid/add.hpp"
#include "alg/monoid/minmax.hpp"

template <typename E>
struct ActedMonoid_MinMax_Add {
  using Monoid_X = Monoid_MinMax<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a) {
    E lo = (x.fi == numeric_limits<E>::max() ? x.fi : x.fi + a);
    E hi = (x.se == numeric_limits<E>::lowest() ? x.se : x.se + a);
    return {lo, hi};
  }
};
