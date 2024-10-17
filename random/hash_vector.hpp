#pragma once

#include "random/base.hpp"
#include "mod/modint61.hpp"

template <typename T>
u64 hash_vector(vc<T> X) {
  using mint = modint61;
  static vc<mint> hash_base;
  int n = len(X);
  while (len(hash_base) <= n) { hash_base.eb(RNG(mint::get_mod())); }
  mint H = 0;
  FOR(i, n) H += hash_base[i] * mint(X[i]);
  H += hash_base[n];
  return H.val;
}

template <typename T, int K>
u64 hash_array(array<T, K> X) {
  using mint = modint61;
  static array<mint, K> hash_base{};
  if (hash_base[0] == mint(0)) FOR(i, K) hash_base[i] = RNG_64();
  mint H = 0;
  FOR(i, K) H += hash_base[i] * mint(X[i]);
  return H.val;
}
