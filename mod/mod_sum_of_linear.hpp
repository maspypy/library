#include "mod/floor_sum_of_linear.hpp"

i128 mod_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {
  /*
  sum_{x in [L,R)} (ax + b mod mod)
  */
  i128 s = a * L + b;
  i128 t = a * (R - 1) + b;
  i128 sum = (s + t) * (R - L) / 2;
  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);
  return sum - fsum * mod;
}
