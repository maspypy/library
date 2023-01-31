#include "random/base.hpp"

template <typename T>
u64 hash_pair(pair<T, T> X) {
  static ll hash_base = 0;
  if (hash_base == 0) hash_base = RNG_64();
  return hash_base * X.fi + X.se;
}
