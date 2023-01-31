// f(q, l, r)：ceil が q になる範囲が [l, r)
// q == 1 のときには r == INF が入ることに注意
template <typename INT_TYPE, typename F>
void ceil_range(INT_TYPE N, F f, INT_TYPE INF) {
  INT_TYPE q = 1, l = N, r = INF;
  while (1) {
    f(q, l, r);
    if (q == N) break;
    r = l, q = ceil(N, l - 1), l = ceil(N, q);
  }
}
