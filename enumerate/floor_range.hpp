// 商が q の区間 [l,r) を q について昇順
template <typename F>
void floor_range(ll N, F f) {
  assert(N <= (1LL << 50));
  ll sq = sqrtl(N);
  int n = (sq * sq + sq <= N ? sq : sq - 1);
  ll prev = N + 1;
  for (int q = 1; q <= n; ++q) {
    ll x = double(N) / (q + 1) + 1;
    f(q, x, prev), prev = x;
  }
  for (int l = sq; l >= 1; --l) { f(double(N) / l, l, l + 1); }
}
