#include "alg/monoid/add.hpp"
#include "alg/monoid/mul.hpp"

template <typename E>
struct ActedMonoid_Add_Mul {
  using MX = Monoid_Add<E>;
  using MA = Monoid_Mul<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) { return x * a; }
};
