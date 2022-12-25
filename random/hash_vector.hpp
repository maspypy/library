#pragma once

#include "random/base.hpp"
#include "mod/modint61.hpp"

template <typename T>
ll hash_vector(vc<T> X) {
  using mint = modint61;
  static vc<mint> hash_base;
  int n = len(X);
  while (len(hash_base) <= n) { hash_base.eb(RNG(mint::get_mod())); }
  mint H = 0;
  FOR(i, n) H += hash_base[i] * mint(X[i]);
  H += hash_base[n];
  return H.val;
}

template <typename T>
ll hash_pair(pair<T, T> X) {
  static ll hash_base = 0;
  if (hash_base == 0) hash_base = RNG_64();
  return hash_base * X.fi + X.se;
}
