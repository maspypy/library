#include "alg/monoid/cntminmincnt.hpp"
#include "alg/monoid/add.hpp"

template <typename E>
struct Lazy_CntMinMincnt_Add {
  using MX = Monoid_CntMinMincnt<E>;
  using MA = Monoid_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    auto [xcnt, xmin, xmincnt] = x;
    if (xmin == numeric_limits<ll>::max()) return x;
    return {xcnt, xmin + a, xmincnt};
  }
};
