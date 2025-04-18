
// floor path で (x,y) から x 方向に進むときに p^xq^yx^k1y^k2 を足す
template <typename T, int K1, int K2>
struct Monoid_for_floor_sum_pq {
  using ARR = array<array<T, K2 + 1>, K1 + 1>;
  struct Data {
    ARR dp;
    T dx, dy;
    T prod;
  };

  static pair<T, T> &get_pq() {
    static pair<T, T> pq = {T(1), T(1)};
    return pq;
  }

  static void set_pq(T p, T q) { get_pq() = {p, q}; }

  using value_type = Data;
  using X = value_type;
  static X op(X a, X b) {
    static constexpr int n = max(K1, K2);
    static T comb[n + 1][n + 1];
    if (comb[0][0] != T(1)) {
      comb[0][0] = T(1);
      FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j]; }
    }

    array<T, K1 + 1> pow_x;
    array<T, K2 + 1> pow_y;
    pow_x[0] = 1, pow_y[0] = 1;
    FOR(i, K1) pow_x[i + 1] = pow_x[i] * a.dx;
    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;

    FOR(i, K1 + 1) FOR(j, K2 + 1) { b.dp[i][j] *= a.prod; }

    // +dy
    FOR(i, K1 + 1) {
      FOR_R(j, K2 + 1) {
        T x = b.dp[i][j];
        FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;
      }
    }

    // +dx
    FOR(j, K2 + 1) {
      FOR_R(i, K1 + 1) { FOR(k, i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }
    }

    a.dx += b.dx, a.dy += b.dy, a.prod *= b.prod;
    return a;
  }

  static X to_x() {
    X x = unit();
    x.dp[0][0] = 1, x.dx = 1, x.prod = get_pq().fi;
    return x;
  }
  static X to_y() {
    X x = unit();
    x.dy = 1, x.prod = get_pq().se;
    return x;
  }
  static constexpr X unit() { return {ARR{}, T(0), T(0), T(1)}; }
  static constexpr bool commute = 0;
};
