
/*
2 面体群. 長さ n の文字列に作用する.
(+1,k): i 文字目が +i+k 文字目に移動. S は S[-k:N-k) に変化.
(-1,k): i 文字目が -i+k 文字目に移動. S は S[k:k-N).
これは revS[N-1-k:N-1-k+N] とも言える.
https://qoj.ac/contest/1576/problem/8512
*/
template <int id>
struct Dihedral {
  using value_type = pair<int, int>;
  using X = value_type;

  static inline int n = 0;
  static void set_n(int m) { n = m; }

  static X op(X x, X y) {
    // x をやったあと y
    auto [t1, k1] = x;
    auto [t2, k2] = y;
    int t = t1 * t2;
    int k = bmod<int>(t2 * k1 + k2, n);
    return {t, k};
  }
  static X inverse(X x) {
    if (x.fi == 1) x.se = bmod<int>(n - x.se, n);
    return x;
  }
  static constexpr X id() { return {1, 0}; }
  static constexpr bool commute = 0;

  static X cyclic_shift_left(ll k) { return cyclic_shift_right(-k); }
  static X cyclic_shift_right(ll k) {
    k = bmod<ll>(k, n);
    return {1, k};
  }
  static X reverse() { return {-1, n - 1}; }
  template <typename STRING>
  static STRING apply(X f, STRING A) {
    assert(len(A) == n);
    auto [t, x] = f;
    if (t == 1) {
      rotate(A.begin(), A.begin() + n - x, A.end());
      return A;
    }
    std::reverse(all(A));
    rotate(A.begin(), A.begin() + (n - 1 - x), A.end());
    return A;
  }
};
