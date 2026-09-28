template <typename BS, typename F>
void enumerate_bits_bitset(BS& b, int L, int R, F&& f) {
  if (L >= len(b)) return;
  int p = (b[L] ? L : b._Find_next(L));
  while (p < R) {
    f(p);
    p = b._Find_next(p);
  }
}

template <typename UINT, typename F>
inline void enumerate_all_bit(UINT s, F&& f) {
  static_assert(is_unsigned<UINT>::value);
  while (s) {
    f(lowbit(s));
    s &= s - 1;
  }
}

template <typename UINT, bool inc_empty, typename F>
inline void enumerate_all_subset(UINT s, F&& f) {
  static_assert(is_unsigned<UINT>::value);
  for (UINT t = s; t; t = (t - 1) & s) f(t);
  if constexpr (inc_empty) f(0);
}
