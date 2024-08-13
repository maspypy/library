// N=10 だと dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} みたいになる
// hashmap より数倍高速
template <typename T>
struct Array_On_Floor {
  u64 N;
  u32 t, sq;
  vc<T> dat;
  Array_On_Floor() {}
  Array_On_Floor(u64 N, T default_value = T{}) : N(N) {
    assert(N <= u64(1) << 50);
    sq = sqrtl(N);
    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);
    dat.resize(t + sq, default_value);
  }

  u32 size() { return dat.size(); }

  T& operator[](u64 d) {
    int i = get_index(d);
    return dat[i];
  }

  inline u32 get_index(u64 d) {
    assert(d > 0);
    if (d <= t) return d - 1;
    return dat.size() - u32(double(N) / d);
  }

  // dat[i] に対応する floor
  u64 get_floor(u32 i) { return (i < t ? 1 + i : double(N) / (t + sq - i)); }

  template <typename F>
  void enumerate_all(F f) {
    FOR(i, len(dat)) { f(get_floor(i), dat[i]); }
  }
};