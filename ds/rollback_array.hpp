// Source: https://github.com/maspypy/library/blob/main/ds/rollback_array.hpp

template <typename T>
struct Rollback_Array {
  int N;
  vc<T> dat;
  vc<pair<int, T>> history;

  Rollback_Array() {}
  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}
  Rollback_Array(int N) : N(N), dat(N) {}
  template <typename F>
  Rollback_Array(int N, F f) : N(N) {
    dat.reserve(N);
    FOR(i, N) dat.eb(f(i));
  }

  int time() { return len(history); }
  void rollback(int t) {
    while (t < time()) {
      auto [idx, v] = POP(history[i]);
      dat[idx] = v;
    }
  }
  T get(int idx) { return dat[idx]; }
  void set(int idx, T x) {
    history.eb(idx, dat[idx]);
    dat[idx] = x;
  }

  vc<T> get_all() { return dat; }
};
