#include "alg/monoid/affine.hpp"

// 1 次元ベクトル空間に、アフィン変換が作用
template <typename T>
struct ActedSet_Affine {
  using Monoid_A = Monoid_Affine<T>;
  using A = typename Monoid_A::value_type;
  using S = T;
  static S act(const S &x, const A &g) { return g.fi * x + g.se; }
};
