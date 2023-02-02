#include "linalg/xor/vector_space.hpp"

template <typename UINT>
struct Mono {
  using value_type = Vector_Space<UINT>;
  using X = value_type;
  static X op(X x, X y) { return Vector_Space<UINT>::merge(x, y); }
  static constexpr X unit() { return {}; }
  static constexpr bool commute = 1;
};
