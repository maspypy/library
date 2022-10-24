#pragma once
#include "alg/group/gl2.hpp"

template <typename T>
struct GSet_GL2_Vec {
  using Group = Group_GL2<T>;
  using G = typename Group::value_type;
  using X = pair<T, T>;
  static X act(const G &g, const X &x) {
    return {g[0][0] * x.fi + g[0][1] * x.se, g[1][0] * x.fi + g[1][1] * x.se};
  }
};