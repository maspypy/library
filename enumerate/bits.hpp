template <typename F>
void enumerate_bits(int s, F f) {
  while (s) {
    int i = __builtin_ctz(s);
    f(i);
    s ^= 1 << i;
  }
}

template <typename F>
void enumerate_bits(u64 s, F f) {
  while (s) {
    int i = __builtin_ctzll(s);
    f(i);
    s ^= 1 << i;
  }
}

template <typename BS, typename F>
void enumerate_bits_bitset(BS& b, int L, int R, F f) {
  int p = (b[L] ? L : b._Find_next(L));
  while (p < R) {
    f(p);
    p = b._Find_next(p);
  }
}