#include "alg/monoid_max.hpp"

template <typename E, E INF>
struct Lazy_Max_Max {
  using MX = Monoid_Max<E, INF>;
  using MA = Monoid_Max<E, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return max(x, a); }
};
