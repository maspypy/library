#include "alg/monoid/add.hpp"
#include "alg/monoid/min.hpp"

template <typename E>
struct Lazy_Min_Add {
  using MX = Monoid_Min<E>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (x == numeric_limits<E>::max()) return x;
    return x + a;
  }
};
