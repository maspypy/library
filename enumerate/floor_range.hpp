// f(q, l, r)：商が q になる範囲が [l, r)
template <typename INT_TYPE, typename F>
void floor_range(INT_TYPE N, F f) {
  INT_TYPE q = 1, r = N + 1;
  while (1) {
    INT_TYPE l = N / (q + 1) + 1;
    f(q, l, r);
    if (q == N) break;
    r = l, q = N / (l - 1);
  }
}
