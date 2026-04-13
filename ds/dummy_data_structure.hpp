#include "alg/monoid/dummy.hpp"

struct Dummy_Data_Structure {
  using MX = Monoid_Dummy;
  using T = typename MX::value_type;
  void build(const vc<T>& A) {}
};