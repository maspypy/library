#include "alg/monoid/cntsummin.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct Lazy_CntSumMin_Add {
  using MX = Monoid_CntSumMin<E>;
  using MA = Monoid_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    auto [xc, xs, xm] = x;
    xm = (xm == numeric_limits<E>::max() ? xm : xm + a);
    return {xc, xs + xc * a, xm};
  }
};
