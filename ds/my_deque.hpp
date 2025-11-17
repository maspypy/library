
template <typename T>
struct My_Deque {
  vc<T> dat1, dat2;

  vc<T> get_all() {
    vc<T> ANS(len(dat1) + len(dat2));
    FOR(i, len(dat1)) ANS[i] = dat1[len(dat1) - 1 - i];
    FOR(i, len(dat2)) ANS[len(dat1) + i] = dat2[i];
    return ANS;
  }

  int size() { return len(dat1) + len(dat2); }
  bool empty() { return dat1.empty() && dat2.empty(); }
  void reverse() { swap(dat1, dat2); }

  void push_back(T x) { dat2.push_back(x); }
  void push_front(T x) { dat1.push_back(x); }

  void push(T x) { push_back(x); }

  void clear() { dat1.clear(), dat2.clear(); }
  void pop_front() {
    assert(!empty());
    if (size() == 1) return clear();
    if (dat1.empty()) rebuild();
    dat1.pop_back();
  }

  void pop_back() {
    if (size() == 1) return clear();
    if (dat2.empty()) rebuild();
    dat2.pop_back();
  }

  T& operator[](int i) {
    assert(0 <= i && i < size());
    return (i < len(dat1) ? dat1[len(dat1) - 1 - i] : dat2[i - len(dat1)]);
  }

  T& front() { return (*this)[0]; }
  T& back() { return (*this)[size() - 1]; }

 private:
  void rebuild() {
    ::reverse(all(dat1));
    concat(dat1, dat2);
    int m = len(dat1) / 2;
    dat2 = {dat1.begin() + m, dat1.end()};
    dat1.resize(m);
    ::reverse(all(dat1));
  }
};