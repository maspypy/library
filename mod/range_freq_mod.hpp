// count x in [L,R) such that (x mod mod) in [lo,hi)
template <typename I>
I range_freq_mod(I L, I R, I lo, I hi, I mod) {
  assert(0 <= lo && lo <= hi && hi <= mod);
  auto f = [&](I x) -> I {
    auto [q, r] = divmod<I>(x, mod);
    I a = max<I>(lo, 0), b = min<I>(hi, r);
    return q * (hi - lo) + max<I>(b - a, 0);
  };
  return f(R) - f(L);
}
