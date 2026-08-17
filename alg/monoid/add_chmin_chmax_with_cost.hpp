template <typename T>
struct Monoid_Add_Chmin_Chmax_with_Cost {
  // clamp(x+a,l,r) は (a,0,0,l-a,r-a) とする
  // eval_cost(f,x) すると、add, chmax, chmin による x の変化量が入る
  struct F {
    T a, b, c, x1, x2;
    F(T a = 0, T b = 0, T c = 0, T x1 = -infty<T>, T x2 = infty<T>)
        : a(a), b(b), c(c), x1(x1), x2(x2) {}
    // add, chmax, chmin
    tuple<T, T, T> eval_cost(T x) {
      return {a, b + max<T>(x1 - x, 0), c + max<T>(x - x2, 0)};
    }
    T eval(T x) {
      auto [add, ma, mi] = eval_cost(x);
      return x + add + ma - mi;
    }
  };
  using value_type = F;
  using X = value_type;
  static X op(X L, X R) {
    X M;
    T x1 = L.x1, x2 = L.x2;
    T y1 = R.x1 - L.a - L.b + L.c, y2 = R.x2 - L.a - L.b + L.c;
    M.a = L.a + R.a;
    if (y1 < x1) M.b = L.b + R.b, M.x1 = x1;
    elif (y1 < x2) M.b = L.b + R.b, M.x1 = y1;
    else M.b = L.b + R.b + y1 - x2, M.x1 = x2;
    if (y2 < x1) M.c = L.c + R.c + x1 - y2, M.x2 = x1;
    elif (y2 < x2) M.c = L.c + R.c, M.x2 = y2;
    else M.c = L.c + R.c, M.x2 = x2;
    return M;
  }

  static constexpr X unit() { return F(); }
  static constexpr bool commute = 0;
};
