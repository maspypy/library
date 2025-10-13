#include "ds/unionfind/unionfind.hpp"

// 末尾代入
// find min of (a[i],...,a[p-1])
template <typename T>
struct Suffix_Max {
  // 内部的な処理としては a ではなく ANS を管理する.
  // ANS[0],...,ANS[p] に chmax(x) が来ると思う
  int N, p;
  UnionFind uf;
  vc<T> ANS;
  vc<pair<T, int>> st;  // (value, uf root)
  Suffix_Max(int N) : N(N), p(0), uf(N + 1), ANS(N + 1, -infty<T>) {
    st.reserve(N);
  }

  void reset() {
    uf.reset();
    fill(all(ANS), -infty<T>);
    st.clear();
    p = 0;
  }

  void set(int i, T x) {
    assert(p == i);
    while (!st.empty() && st.back().fi <= x) {
      uf.merge(p, st.back().se);
      st.pop_back();
    }
    int r = uf[p++];
    ANS[r] = x, st.eb(x, r);
  }
  T query(int i) {
    assert(i <= p);
    return ANS[uf[i]];
  }
};