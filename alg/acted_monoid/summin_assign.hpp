// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/summin_assign.hpp
#include "alg/monoid/summin.hpp"
#include "alg/monoid/assign.hpp"

template <typename E>
struct ActedMonoid_SumMin_Assign {
  static_assert(is_save_v<E, int> || is_same_v<E, ll>);
  using Monoid_X = Monoid_SumMin<E>;
  using Monoid_A = Monoid_Assign<ll>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X& x, const A& a, const ll& size) {
    if (a == Monoid_A::id()) return x;
    return {E(size) * a, a};
  }
};
