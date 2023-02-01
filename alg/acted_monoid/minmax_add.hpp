#include "alg/monoid/add.hpp"
#include "alg/monoid/minmax.hpp"

template <typename E>
struct ActedMonoid_MinMax_Add {
  using Monoid_X = Monoid_MinMax<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    E lo = (x.fi == INF<E> ? x.fi : x.fi + a);
    E hi = (x.se == -INF<E> ? x.se : x.se + a);
    return {lo, hi};
  }
};
