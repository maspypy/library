template <typename T, int K, bool upper = false>
struct Monoid_MinPlus_Matrix {
  using X = array<array<T, K>, K>;
  using value_type = X;

  static X op(const X& x, const X& y) {
    X z;
    if constexpr (upper) {
      FOR(a, K) {
        FOR(c, a) z[a][c] = infty<T>;
        FOR(c, a, K) {
          T v = infty<T>;
          FOR(b, a, c + 1) v = min(v, x[a][b] + y[b][c]);
          z[a][c] = v;
        }
      }
    } else {
      FOR(a, K) FOR(c, K) {
        T v = infty<T>;
        FOR(b, K) v = min(v, x[a][b] + y[b][c]);
        z[a][c] = v;
      }
    }
    return z;
  }

  static constexpr X id() {
    X x{};
    FOR(i, K) FOR(j, K) x[i][j] = (i == j ? T(0) : infty<T>);
    return x;
  }

  static constexpr bool commute = false;
};