#pragma once

#include "alg/monoid/assign.hpp"
#include "alg/monoid/add_array.hpp"

// 0, 1, ..., K 乗和
template <typename T, int K>
struct ActedMonoid_Power_Sums_Assign {
  using Monoid_X = Monoid_Add_Array<T, K + 1>;
  using Monoid_A = Monoid_Assign<T, -1>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    if (a == Monoid_A::unit()) return x;
    X y;
    T pow = 1;
    FOR(i, K + 1) { y[i] = x[0] * pow, pow *= a; }
    return y;
  }
};
