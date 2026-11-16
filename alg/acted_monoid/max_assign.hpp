// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/max_assign.hpp
#include "alg/monoid/max.hpp"
#include "alg/monoid/assign.hpp"

template <typename E>
struct ActedMonoid_Max_Assign {
  static_assert(is_same_v<E, int> || is_same_v<E, ll>);
  using Monoid_X = Monoid_Max<E>;
  using Monoid_A = Monoid_Assign<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    return (a == Monoid_A::id() ? x : a);
  }
};
