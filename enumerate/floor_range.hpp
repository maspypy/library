// 商が q の区間 [l,r) を q について昇順
template <typename F>
void floor_range(u64 N, F f, bool Q_ASC = true, bool INCLUDE_Q_IS_0 = false) {
  u64 sq = sqrtl(N);
  u32 n = (sq * sq + sq <= N ? sq : sq - 1);
  if (Q_ASC) {
    if (INCLUDE_Q_IS_0) f(0, N + 1, infty<ll>);
    for (u32 q = 1; q <= n; ++q) { f(q, N / (q + 1) + 1, N / q + 1); }
    for (u32 l = sq; l >= 1; --l) { f(N / l, l, l + 1); }
  } else {
    for (u32 l = 1; l <= sq; ++l) { f(N / l, l, l + 1); }
    for (u32 q = n; q >= 1; --q) { f(q, N / (q + 1) + 1, N / q + 1); }
    if (INCLUDE_Q_IS_0) f(0, N + 1, infty<ll>);
  }
}
