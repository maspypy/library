#include "alg/monoid/cntsummax.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct Lazy_CntSumMax_Add {
  using MX = Monoid_CntSumMax<E>;
  using MA = Monoid_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    auto [xc, xs, xm] = x;
    xm = (xm == numeric_limits<E>::lowest() ? xm : xm + a);
    return {xc, xs + xc * a, xm};
  }
};
