#pragma once

template <typename T>
struct RollbackArray {
  int N;
  vc<T> dat;
  vc<pair<int, T>> history;

  RollbackArray(vc<T> x) : N(len(x)), dat(x) {}
  template <typename F>
  RollbackArray(int N, F f) : N(N) {
    dat.reserve(N);
    FOR(i, N) dat.eb(f(i));
  }

  int time() { return len(history); }
  void rollback(int t) {
    FOR_R(i, t, time()) {
      auto& [idx, v] = history[i];
      dat[idx] = v;
    }
    history.resize(t);
  }
  T get(int idx) { return dat[idx]; }
  void set(int idx, T x) {
    history.eb(idx, dat[idx]);
    dat[idx] = x;
  }

  vc<T> get_all() {
    vc<T> res(N);
    FOR(i, N) res[i] = get(i);
    return res;
  }
};
