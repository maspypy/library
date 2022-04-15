#include "alg/group_add.hpp"
#include "alg/monoid_minmax.hpp"

template <typename E, E INF>
struct Lazy_MinMax_Add {
  using MX = Monoid_MinMax<E, INF>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { 
    return {min(INF, x.fi + a), max(-INF, x.se + a)};
  }
};