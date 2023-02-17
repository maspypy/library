// 商が q の区間 [l,r) を q について昇順
template <typename F>
void ceil_range(ll N, F f) {
  assert(N <= (1LL << 50));
  ll sq = sqrtl(N - 1);
  int n = (N <= sq * sq + sq ? sq : sq + 1);
  ll prev = infty<ll>;
  for (int q = 1; q <= sq + 1; ++q) {
    ll x = double(N + q - 1) / q;
    f(q, x, prev), prev = x;
  }
  for (int l = n; l >= 1; --l) { f(double(N + l - 1) / l, l, l + 1); }
}
