#include "alg/monoid/add.hpp"
#include "alg/monoid/minmax.hpp"

template <typename E, E INF>
struct Lazy_MinMax_Add {
  using MX = Monoid_MinMax<E, INF>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    X lo = (x.fi == numeric_limits<X>::max() ? x.fi : x.fi + a);
    X hi = (x.se == numeric_limits<X>::lowest() ? x.se : x.se + a);
    return {lo, hi};
  }
};
