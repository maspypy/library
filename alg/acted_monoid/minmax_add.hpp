#include "alg/monoid/add.hpp"
#include "alg/monoid/minmax.hpp"

template <typename E>
struct Lazy_MinMax_Add {
  using MX = Monoid_MinMax<E>;
  using MA = Monoid_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    E lo = (x.fi == numeric_limits<E>::max() ? x.fi : x.fi + a);
    E hi = (x.se == numeric_limits<E>::lowest() ? x.se : x.se + a);
    return {lo, hi};
  }
};
