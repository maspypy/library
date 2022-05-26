template <typename T>
struct RollbackArray {
  vc<T> dat;
  vc<pair<int, T>> history;

  RollbackArray(vc<T> x) : dat(x) {}

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
};
