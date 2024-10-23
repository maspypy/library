// 全体加算もできるようにしよう
// Monoid_Add<T> を渡す感じで. T は operator< が定義されている必要あり.
template <typename Monoid>
struct Double_End_Queue_Const_Add {
  using MX = Monoid;
  using T = typename MX::value_type;
  vector<T> dat;
  T add;

  Double_End_Queue_Const_Add() : add(MX::unit()) {}
  Double_End_Queue_Const_Add(vc<T>& A) : add(MX::unit()) { build(A); }

  int size() { return dat.size(); }
  bool empty() { return dat.empty(); }
  T min() { return MX::op(dat[0], add); }
  T max() { return MX::op(add, (len(dat) == 1 ? dat[0] : dat[1])); }

  void build(vc<T>& A) {
    add = MX::unit();
    dat = A;
    int n = len(dat);
    FOR_R(i, n) { down(i); }
  }
  void clear() {
    dat.clear(), dat.shrink_to_fit();
    add = 0;
  }

  void push(T x) { dat.eb(x - add), up(); }

  T pop_min() {
    assert(!dat.empty());
    swap(dat[0], dat.back());
    T res = POP(dat);
    down(0);
    return res + add;
  }

  T pop_max() {
    assert(!dat.empty());
    if (len(dat) <= 2) { return POP(dat) + add; }
    swap(dat[1], dat.back());
    T res = POP(dat);
    down(1);
    return res + add;
  }

  template <typename F>
  void enumerate_all(F f) {
    for (auto& x: dat) f(x + add);
  }

private:
  inline int parent(int i) { return (i - 4 + (i & 3)) / 2; }

  void down(int i) {
    int n = len(dat);
    if (i % 2 == 0) {
      while (1) {
        if (i + 1 < n && dat[i + 1] < dat[i]) swap(dat[i], dat[i + 1]);
        int j = i, l = 2 * i + 2, r = 2 * i + 4;
        if (l < n && dat[l] < dat[j]) j = l;
        if (r < n && dat[r] < dat[j]) j = r;
        if (i == j) break;
        swap(dat[i], dat[j]), i = j;
      }
    } else {
      while (1) {
        if (dat[i] < dat[i - 1]) swap(dat[i - 1], dat[i]);
        int j = i, l = 2 * i + 1, r = 2 * i + 3;
        if (r >= n) --r;
        if (l >= n) --l;
        if (l < n && dat[j] < dat[l]) j = l;
        if (r < n && dat[j] < dat[r]) j = r;
        if (i == j) break;
        swap(dat[i], dat[j]), i = j;
        if (i % 2 == 0) break;
      }
    }
  }

  void up() {
    int i = len(dat) - 1;
    if (2 <= i && i % 2 == 0) {
      int p = parent(i) ^ 1;
      if (dat[p] < dat[i]) { swap(dat[i], dat[p]), i = p; }
    }
    if (i % 2 == 1 && dat[i] < dat[i - 1]) { swap(dat[i - 1], dat[i]), --i; }
    if (i % 2 == 0) {
      while (i >= 2) {
        int p = parent(i);
        if (!(dat[i] < dat[p])) break;
        swap(dat[p], dat[i]), i = p;
      }
      return;
    }
    while (i >= 3) {
      int p = parent(i);
      if (!(dat[p] < dat[i])) break;
      swap(dat[p], dat[i]), i = p;
    }
  }
};
