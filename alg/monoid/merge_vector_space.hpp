#include "linalg/xor/vector_space.hpp"

template <typename UINT, int MAX_DIM>
struct Merge_Vector_Space {
  using value_type = Vector_Space<UINT, MAX_DIM>;
  using X = value_type;
  static X op(X x, X y) {
    if (len(x) < len(y)) swap(x, y);
    for (UINT v : y.dat) {
      x.add_element(v);
    }
    return x;
  }
  static constexpr X unit() { return {}; }
  static constexpr bool commute = 1;
};
