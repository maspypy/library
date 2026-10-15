// Source: https://github.com/maspypy/library/blob/main/ds/dummy_data_structure.hpp
#include "alg/monoid/dummy.hpp"

struct Dummy_Data_Structure {
  using MX = Monoid_Dummy;
  using T = typename MX::value_type;
  void build(const vc<T>& A) {}
};