
// sum i^kfloor: floor path で (x,y) から x 方向に進むときに x^ky を足す
template <typename T, int K>
struct Monoid_for_floor_sum {
  using ARR = array<array<T, K + 1>, 2>;
  struct Data {
    ARR dp;
    T dx, dy;
  };

  using value_type = Data;
  using X = value_type;
  static X op(X a, X b) {
    static T comb[K + 1][K + 1];
    if (comb[0][0] != T(1)) {
      comb[0][0] = T(1);
      FOR(i, K) FOR(j, i + 1) {
        comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j];
      }
    }
    T pow = 1;
    FOR(j, K + 1) {
      FOR(i, K - j + 1) {
        T x = comb[i + j][i];
        a.dp[0][i + j] += b.dp[0][i] * pow * x;
        a.dp[1][i + j] += (b.dp[0][i] * a.dy + b.dp[1][i]) * pow * x;
      }
      pow *= a.dx;
    }
    a.dx += b.dx, a.dy += b.dy;
    return a;
  }

  static X to_x() {
    X x = unit();
    x.dp[0][0] = 1, x.dx = 1;
    return x;
  }
  static X to_y() {
    X x = unit();
    x.dy = 1;
    return x;
  }
  static constexpr X unit() { return {ARR{}, T(0), T(0)}; }
  static constexpr bool commute = 0;
};