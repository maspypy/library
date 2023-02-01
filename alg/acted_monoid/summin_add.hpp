#include "alg/monoid/summin.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct ActedMonoid_SumMin_Add {
  using Monoid_X = Monoid_SumMin<E>;
  using Monoid_A = Monoid_Add<E>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X& x, const A& a, const ll& size) {
    auto [xs, xm] = x;
    xm = (xm == INF<E> ? xm : xm + a);
    return {xs + E(size) * a, xm};
  }
};
