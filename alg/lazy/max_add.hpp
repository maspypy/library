#include "alg/monoid/add.hpp"
#include "alg/monoid/max.hpp"

template <typename E>
struct Lazy_Max_Add {
  using MX = Monoid_Max<E>;
  using MA = Group_Add<E>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static constexpr X act(const X &x, const A &a) {
    if (x == numeric_limits<E>::lowest()) return x;
    return x + a;
  }
};
