#include "alg/monoid/add.hpp"
#include "alg/monoid/add_pair.hpp"

template <typename E>
struct Lazy_CntSum_Add {
  using MX = Monoid_Add_Pair<E>;
  using MA = Monoid_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    return {x.fi, x.se + x.fi * a};
  }
};
