// (L,R,a,b,c)
// position = clamp(x,L,R) + a
// chmax_cost = b + max(L - x, 0)
// chmin_cost = c + max(x - R, 0)
template <typename T>
struct Monoid_Add_Chmin_Chmax_with_Cost {
  struct S {
    T L, R, a, b, c;
  };
  using value_type = S;
  using X = value_type;

  // Return {position, chmax_cost, chmin_cost}
  static tuple<T, T, T> eval(const X& f, T x) {
    auto [L, R, a, b, c] = f;
    T chmax_cost = b + max<T>(L - x, 0);
    T chmin_cost = c + max<T>(x - R, 0);
    return {clamp(x, L, R) + a, chmax_cost, chmin_cost};
  }

  // g(f(x))
  static X op(const X& f, const X& g) {
    auto [Lf, Rf, af, bf, cf] = f;
    auto [Lg, Rg, ag, bg, cg] = g;
    T L = clamp(Lg - af, Lf, Rf);
    T R = clamp(Rg - af, Lf, Rf);
    T y_at_L = get<0>(eval(f, L));
    T y_at_R = get<0>(eval(f, R));
    T b = bf + max<T>(Lf - L, 0) + bg + max<T>(Lg - y_at_L, 0);
    T c = cf + max<T>(R - Rf, 0) + cg + max<T>(y_at_R - Rg, 0);
    T a = clamp(y_at_L, Lg, Rg) + ag - L;
    return {L, R, a, b, c};
  }

  // x -> clamp(x + add, low, high)
  static constexpr X add_clamp(T add, T low, T high) {
    return {low - add, high - add, add, 0, 0};
  }
  // x -> clamp(x, low, high) + add
  static constexpr X clamp_add(T add, T low, T high) {
    return add_clamp(add, low + add, high + add);
  }
  static constexpr X id() { return {-infty<T>, infty<T>, 0, 0, 0}; }
  static constexpr bool commute = false;
};
