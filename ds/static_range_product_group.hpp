
template <typename Monoid>
struct Static_Range_Product_Group {
  using MX = Monoid;
  using X = typename MX::value_type;
  int n;
  vc<X> dat;
  Static_Range_Product_Group() {}
  void build(vc<X>& A) {
    n = len(A);
    dat.assign(n + 1, MX::unit());
    for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);
  }
  X prod(int l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }
};