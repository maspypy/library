template <typename T, typename F>
void floor_range(T N, F f) {
  ll thresh = 1'000'000'000'000;
  ll sq = sqrtl(N);
  int n = (sq * sq + sq <= N ? sq : sq - 1);
  if (N <= thresh) {
    ll prev = N + 1;
    for (int q = 1; q <= n; ++q) {
      ll x = double(N) / (q + 1) + 1;
      f(q, x, prev), prev = x;
    }
    for (int l = sq; l >= 1; --l) { f(double(N) / l, l, l + 1); }
  } else {
    ll prev = N + 1;
    for (int q = 1; q <= n; ++q) {
      ll x = N / (q + 1) + 1;
      f(q, x, prev), prev = x;
    }
    for (int l = sq; l >= 1; --l) { f(N / l, l, l + 1); }
  }
}
