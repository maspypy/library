u64 mod_inv_u64(u64 a) {
  assert(a & 1);
  u64 x = 1;
  x = x * (2ULL - a * x);
  x = x * (2ULL - a * x);
  x = x * (2ULL - a * x);
  x = x * (2ULL - a * x);
  x = x * (2ULL - a * x);
  x = x * (2ULL - a * x);
  assert(a * x == 1);
  return x;
}
