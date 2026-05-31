// V[L],...,V[R-1] を大きさ R-L の vector で管理する
template <typename T>
struct OffsetVector {
  int off;
  vc<T> dat;
  OffsetVector(int L = 0, int R = 0, T t = {}) : off(L), dat(R - L, t) {}
  T& operator[](int i) { return dat[i - off]; }
  const T& operator[](int i) const { return dat[i - off]; }
  int size() const { return dat.size(); }
  int L() const { return off; }
  int R() const { return off + (dat.size()); }
};