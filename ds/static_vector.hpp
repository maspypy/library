// 固定のサイズ上限をもつ vector
template <typename T, int N>
struct Static_Vector {
  array<T, N> dat;
  int n = 0;

  int size() const { return n; }
  bool empty() const { return n == 0; }

  T& operator[](int i) { return dat[i]; }
  const T& operator[](int i) const { return dat[i]; }

  void push_back(const T& x) { dat[n++] = x; }
  void push_back(T&& x) { dat[n++] = move(x); }

  template <typename... Args>
  T& emplace_back(Args&&... args) {
    return dat[n++] = T(forward<Args>(args)...);
  }

  auto begin() { return dat.begin(); }
  auto end() { return dat.begin() + n; }
  auto begin() const { return dat.begin(); }
  auto end() const { return dat.begin() + n; }
  void clear() { n = 0; }
  using iterator = typename array<T, N>::iterator;
  iterator insert(iterator pos, const T& x) {
    assert(n < N);
    int k = pos - begin();
    dat[n++] = x;
    rotate(begin() + k, end() - 1, end());
    return begin() + k;
  }
};