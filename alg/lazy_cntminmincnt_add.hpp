#include "alg/monoid_cntminmincnt.hpp"
#include "alg/group_add.hpp"

struct Lazy_CntMinMincnt_Add {
  using MX = Monoid_CntMinMincnt;
  using MA = Group_Add<ll>;
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