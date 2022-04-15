#include "alg/group_add.hpp"
#include "alg/monoid_min.hpp"

template <typename E, E INF>
struct Lazy_Min_Add {
  using MX = Monoid_Min<E, INF>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    return min(MX::unit(), x + a);
  }
};