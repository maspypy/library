#include "alg/monoid/cntsummax.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct ActedMonoid_CntSumMax_Add {
  using Monoid_X = Monoid_CntSumMax<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X& x, const A& a) {
    auto [xc, xs, xm] = x;
    xm = (xm == numeric_limits<E>::lowest() ? xm : xm + a);
    return {xc, xs + xc * a, xm};
  }
};
