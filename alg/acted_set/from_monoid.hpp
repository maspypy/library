template <typename Monoid>
struct ActedSet_From_Monoid {
  using Monoid_A = Monoid;
  using A = typename Monoid::value_type;
  using S = A;
  static S act(const S &x, const A &g) { return Monoid::op(x, g); }
};
