// 1 次元ベクトル空間に、アフィン変換が作用
template <typename T>
struct GSet_Affine {
  using Group = Group_Affine<T>;
  using G = typename Group::value_type;
  using X = T;
  static X act(const G &g, const X &x) { return g.fi * x + g.se; }
};
