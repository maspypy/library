// f(q, l, r)：商が q になる範囲が [l, r)
template <typename F>
void floor_range(ll N, F f) {
  ll q = 1;
  ll r = N + 1;
  while (1) {
    ll l = N / (q + 1) + 1;
    f(q, l, r);
    if (q == N) break;
    r = l;
    q = N / (l - 1);
  }
}
