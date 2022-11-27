// max(x+a,b) と表せる関数の合成
template <typename E>
struct Monoid_Add_Chmax {
  using value_type = pair<E, E>;
  using X = value_type;
  static constexpr E L_INF = numeric_limits<E>::lowest();

  static X op(X x, X y) {
    auto [a, c] = x;
    auto [d, f] = y;
    a = a + d;
    c = (c == L_INF ? c : c + d);
    c = max(c, f);
    return {a, c};
  }

  static E eval(X f, E x) { return max(x + f.fi, f.se); }
  static X add(E a) { return {a, L_INF}; }
  static X chmax(E c) { return {0, c}; }

  static constexpr X unit() { return {0, L_INF}; }
  static constexpr bool commute = 0;
};