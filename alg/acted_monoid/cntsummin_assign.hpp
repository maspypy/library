#include "alg/monoid/cntsummin.hpp"
#include "alg/monoid/assign.hpp"

template <typename E, ll none_val>
struct ActedMonoid_CntSumMin_Assign {
  static constexpr ll INF = 1LL << 60;
  using MX = Monoid_CntSumMin<E>;
  using MA = Monoid_Assign<ll, none_val>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    if (a == MA::unit()) return x;
    auto [xc, xs, xm] = x;
    return {xc, xc * a, a};
  }
};
