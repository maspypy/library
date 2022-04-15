#include "alg/monoid_min.hpp"

template <typename E, E INF>
struct Lazy_Min_Min {
  using MX = Monoid_Min<E, INF>;
  using MA = Monoid_Min<E, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return min(x, a); }
};
