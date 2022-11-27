#include "alg/monoid/cntsummin.hpp"
#include "alg/monoid/add.hpp"

struct Lazy_CntSumMin_Add {
  static constexpr ll INF = 1LL << 60;
  using MX = Monoid_CntSumMin;
  using MA = Monoid_Add<ll>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    auto [xc, xs, xm] = x;
    return {xc, xs + xc * a, xm + a};
  }
};
