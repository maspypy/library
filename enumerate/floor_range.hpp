// 商が q の区間 [l,r) を q について昇順
template <typename F>
void floor_range(u64 N, F f) {
  assert(N <= (u64(1) << 50));
  u64 sq = sqrtl(N);
  u32 n = (sq * sq + sq <= N ? sq : sq - 1);
  u64 prev = N + 1;
  for (u32 q = 1; q <= n; ++q) {
    u64 x = double(N) / (q + 1) + 1;
    f(q, x, prev), prev = x;
  }
  for (u32 l = sq; l >= 1; --l) { f(u64(double(N) / l), l, l + 1); }
}
