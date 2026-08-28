
template <typename TREE>
struct Monoid_Diameter {
  using value_type = pair<int, int>;
  using X = value_type;
  static inline const TREE* tree = nullptr;
  static void set_tree(const TREE& T) { tree = &T; }

  static X op(X L, X R) {
    assert(tree != nullptr);
    if (L.fi == -1) return R;
    if (R.fi == -1) return L;
    auto [a, b] = L;
    auto [c, d] = R;
    for (int v : {c, d}) {
      int ab = tree->dist(a, b);
      int av = tree->dist(a, v);
      int bv = tree->dist(b, v);
      int ma = max({ab, av, bv});
      if (ma == ab) {
      }
      elif (ma == av) { b = v; }
      else {
        a = v;
      }
    }
    return {a, b};
  }
  static int eval(const X& D) {
    assert(tree != nullptr);
    return tree->dist(D.fi, D.se);
  }

  static constexpr X unit() { return {-1, -1}; }
  static constexpr bool commute = true;
};