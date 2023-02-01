// f(q, l, r)：ceil が q になる範囲が [l, r)
// q == 1 のときには r == infty<T>
template <typename T, typename F>
void ceil_range(T N, F f) {
  T q = 1, l = N, r = infty<T>;
  while (1) {
    f(q, l, r);
    if (q == N) break;
    r = l, q = ceil(N, l - 1), l = ceil(N, q);
  }
}
