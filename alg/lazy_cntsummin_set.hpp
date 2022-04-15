#include "alg/monoid_cntsummin.hpp"
#include "alg/monoid_set.hpp"

struct Lazy_CntSumMin_Set {
  static constexpr ll INF = 1LL<<60;
  using MX = Monoid_CntSumMin;
  using MA = Monoid_Set<ll, INF>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X& x, const A& a) {
    if (a == INF) return x;
    auto [xc, xs, xm] = x;
    return {xc, xc * a, a};
  }
};
