#include "alg/monoid/add_tuple_3.hpp"
#include "alg/monoid/add.hpp"

// 重み付き多重集合 S の要素に対する、0,1,2 乗和を管理。
template <typename T>
struct ActedMonoid_PowerSum_Add_3 {
  using Monoid_X = Monoid_Add_Tuple_3<T, T, T>;
  using Monoid_A = Monoid_Add<T>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static X act(const X &x, const A &a, const ll &size) {
    auto [x0, x1, x2] = x;
    return {x0, x1 + x0 * a, x2 + (a + a) * x1 + a * a * x0};
  }
};
