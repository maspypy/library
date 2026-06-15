#pragma once

#include "setfunc/bitwise_transform.hpp"

template <typename T>
void superset_zeta(vc<T>& a) {
  bitwise::bitwise_transform<bitwise::trans_type::superset_zeta>(a);
}

template <typename T>
void superset_mobius(vc<T>& a) {
  bitwise::bitwise_transform<bitwise::trans_type::superset_mobius>(a);
}

template <typename T>
void subset_zeta(vc<T>& a) {
  bitwise::bitwise_transform<bitwise::trans_type::subset_zeta>(a);
}

template <typename T>
void subset_mobius(vc<T>& a) {
  bitwise::bitwise_transform<bitwise::trans_type::subset_mobius>(a);
}
