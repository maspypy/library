/*
segtree を考える
現在のポインタの位置がある
もう全部の値が読まれた subtree ではゼータされた状態にしておく
*/
template <typename T>
struct Online_Subset_Zeta {
  int n;
  int p = 0;
  vc<T> A;
  Online_Subset_Zeta(int LOG) : n(LOG), A(1 << n) {}

  // set a[i], return zeta(a)[i]
  T set(int i, T a) {
    assert(p == i);
    T ans = assume(i, 0) + a;
    A[p++] = a;
    int K = lowbit(p);
    for (int k = 0; k < K; ++k)
      for (int j = p - (1 << k); j < p; ++j) A[j] += A[j - (1 << k)];
    return ans;
  }

  // assume a[i], return zeta(a)[i]. not increment the pointer.
  T assume(int i, T ai) {
    assert(p == i);
    T ans = ai;
    // なんとこれだけ？
    for (int j: all_bit<u32>(i)) ans += A[i - (1 << j)];
    return ans;
  }
};
