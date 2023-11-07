u64 integer_kth_root(u64 k, u64 a) {
  assert(k >= 1);
  if (a == 0 || a == 1 || k == 1) return a;
  if (k >= 64) return 1;
  if (k == 2) return sqrtl(a);
  if (a == u64(-1)) --a;
  struct S {
    u64 v;
    S& operator*=(const S& o) {
      v = v <= u64(-1) / o.v ? v * o.v : u64(-1);
      return *this;
    }
  };
  auto power = [&](S x, ll n) -> S {
    S v{1};
    while (n) {
      if (n & 1) v *= x;
      x *= x;
      n /= 2;
    }
    return v;
  };
  u64 res = pow(a, nextafter(1 / double(k), 0));
  while (power(S{res + 1}, k).v <= a) ++res;
  return res;
}
