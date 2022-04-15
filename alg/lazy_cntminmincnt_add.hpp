#include "alg/monoid_cntminmincnt.hpp"
#include "alg/group_add.hpp"

template <ll INF>
struct Lazy_CntMinMincnt_Add {
  using MX = Monoid_CntMinMincnt<INF>;
  using MA = Group_Add<ll>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    auto [xcnt, xmin, xmincnt] = x;
    return {xcnt, min(INF, xmin + a), xmincnt};
  }
};