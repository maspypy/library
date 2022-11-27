// 1 次元ベクトル空間に、アフィン変換が作用
template <typename T>
struct XSet_Affine {
  using Monoid = Monoid_Affine<T>;
  using operator_type = typename Monoid::value_type;
  using element_type = T;
  using X = operator_type;
  using S = element_type;
  static S act(const S &x, const X &g) { return g.fi * x + g.se; }
};
