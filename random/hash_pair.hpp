// Source: https://github.com/maspypy/library/blob/main/random/hash_pair.hpp
#include "random/base.hpp"

template <typename T>
u64 hash_pair(pair<T, T> X) {
  static u64 hash_base = 0;
  if (hash_base == 0) hash_base = RNG_64();
  return hash_base * u64(X.fi) + u64(X.se);
}
