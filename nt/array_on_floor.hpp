// N=10 だと dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} みたいになる
// hashmap より数倍高速
template <typename T>
struct Array_On_Floor {
  ll N;
  int n, sq;
  vc<T> dat;
  Array_On_Floor(ll N, T default_value = T{}) : N(N) {
    assert(N <= (1LL << 50));
    sq = sqrtl(N);
    n = (ll(sq) * sq + sq <= N ? sq : sq - 1);
    dat.resize(n + sq, default_value);
  }

  T& operator[](ll d) {
    int i = get_index(d);
    return dat[i];
  }

  inline int get_index(ll d) {
    assert(d > 0);
    if (d <= n) return d - 1;
    return len(dat) - int(double(N) / d);
  }

  // dat[i] に対応する floor
  ll get_floor(int i) { return (i < n ? 1 + i : double(N) / (n + sq - i)); }

  template <typename F>
  void enumerate_all(F f) {
    FOR(i, len(dat)) { f(get_floor(i), dat[i]); }
  }
};