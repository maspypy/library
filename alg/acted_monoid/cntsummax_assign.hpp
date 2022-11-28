#include "alg/monoid/cntsummax.hpp"
#include "alg/monoid/assign.hpp"

template <typename E, ll none_val>
struct ActedMonoid_CntSumMax_Assign {
  using Monoid_X = Monoid_CntSumMax<E>;
  using Monoid_A = Monoid_Assign<ll, none_val>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X& x, const A& a) {
    if (a == Monoid_A::unit()) return x;
    auto [xc, xs, xm] = x;
    return {xc, xc * a, a};
  }
};
