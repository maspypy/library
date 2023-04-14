template <typename Monoid>
typename Monoid::X monoid_pow(typename Monoid::X x, u64 exp) {
  using X = typename Monoid::X;
  assert(exp >= 0);
  X res = Monoid::unit();
  while (exp) {
    if (exp & 1) res = Monoid::op(res, x);
    x = Monoid::op(x, x);
    exp >>= 1;
  }
  return res;
}