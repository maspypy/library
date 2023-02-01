#include "alg/monoid/add.hpp"
#include "alg/monoid/max.hpp"

template <typename E>
struct ActedMonoid_Max_Add {
  using Monoid_X = Monoid_Max<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    if (x == -INF<E>) return x;
    return x + a;
  }
};
