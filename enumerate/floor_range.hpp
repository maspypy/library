// f(q, l, r)：商が q になる範囲が [l, r)
template <typename T, typename F>
void floor_range(T N, F f) {
  T q = 1, r = N + 1;
  while (1) {
    T l = N / (q + 1) + 1;
    f(q, l, r);
    if (q == N) break;
    r = l, q = N / (l - 1);
  }
}
