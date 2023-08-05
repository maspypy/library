/*
・多重集合を扱う
・[0,k) 番目と [k,N) 番目の sum がとれる
・O(k の変化量の総和 x log N)
*/
template <typename T>
struct Slide_Split_Sum {
  pq<T> ql, rm_ql;
  pqg<T> qr, rm_qr;
  T sl, sr;
  Slide_Split_Sum() : sl(0), sr(0) {}

  inline int size() { return size_l() + size_r(); }
  void insert(T x) {
    if (x <= lmax())
      push_l(x);
    else
      push_r(x);
  }
  void erase(T x) {
    if (x <= lmax()) {
      erase_l(x);
    } else {
      erase_r(x);
    }
  }
  pair<T, T> query(int k) {
    assert(0 <= k && k <= size());
    while (size_l() < k) { push_l(pop_r()); }
    while (size_l() > k) { push_r(pop_l()); }
    return {sl, sr};
  }
  T query_l(int k) { return query(k).fi; }
  T query_r(int k) { return query(size() - k).se; }

private:
  inline T lmax() {
    while (!rm_ql.empty() && ql.top() == rm_ql.top()) rm_ql.pop(), ql.pop();
    return (ql.empty() ? -infty<T> : ql.top());
  }
  inline T rmin() {
    while (!rm_qr.empty() && qr.top() == rm_qr.top()) rm_qr.pop(), qr.pop();
    return (qr.empty() ? infty<T> : qr.top());
  }
  inline T pop_l() {
    while (!rm_ql.empty() && ql.top() == rm_ql.top()) rm_ql.pop(), ql.pop();
    T x = POP(ql);
    sl -= x;
    return x;
  }
  inline T pop_r() {
    while (!rm_qr.empty() && qr.top() == rm_qr.top()) rm_qr.pop(), qr.pop();
    T x = POP(qr);
    sr -= x;
    return x;
  }
  inline void push_l(T x) { ql.emplace(x), sl += x; }
  inline void push_r(T x) { qr.emplace(x), sr += x; }
  inline void erase_l(T x) { rm_ql.emplace(x), sl -= x; }
  inline void erase_r(T x) { rm_qr.emplace(x), sr -= x; }
  inline int size_l() { return ql.size() - rm_ql.size(); }
  inline int size_r() { return qr.size() - rm_qr.size(); }
};
