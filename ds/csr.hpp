
template <typename T>
struct CSR {
  int n;
  bool prepared;
  vc<int> ptr;
  vc<int> I;
  vc<T> dat;

  CSR(int n = 0) : n(n), prepared(false) {}
  void add(int i, const T& x) {
    assert(0 <= i && i < n && !prepared);
    I.eb(i), dat.eb(x);
  }

  void build() {
    assert(!prepared);
    prepared = 1;
    ptr.assign(n + 1, 0);
    for (auto& i : I) ptr[1 + i]++;
    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];
    vc<T> tmp(len(dat));
    FOR(k, len(dat)) {
      int i = I[k];
      tmp[ptr[i]++] = dat[k];
    }
    swap(dat, tmp);
    ptr.pop_back();
    ptr.insert(ptr.begin(), 0);
    I.clear(), I.shrink_to_fit();
  }

  struct range {
    T *first, *last;
    T* begin() const { return first; }
    T* end() const { return last; }
  };

  range operator[](int i) {
    assert(prepared);
    return range{dat.data() + ptr[i], dat.data() + ptr[i + 1]};
  }
};