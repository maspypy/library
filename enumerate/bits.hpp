template <typename BS, typename F>
void enumerate_bits(BS& b, int L, int R, F f) {
  int p = (b[L] ? L : b._Find_next(L));
  while (p < R) {
    f(p);
    p = b._Find_next(p);
  }
}
