#include "alg/monoid/cntsummin.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct ActedMonoid_CntSumMin_Add {
  using Monoid_X = Monoid_CntSumMin<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X& x, const A& a, const ll& size) {
    auto [xs, xm] = x;
    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);
    return {xs + E(size) * a, xm};
  }
};
