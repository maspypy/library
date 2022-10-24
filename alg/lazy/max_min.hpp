#include "alg/monoid/max.hpp"
#include "alg/monoid/min.hpp"

template <typename E>
struct Lazy_Max_Min {
  using MX = Monoid_Max<E>;
  using MA = Monoid_Min<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return min(x, a); }
};
